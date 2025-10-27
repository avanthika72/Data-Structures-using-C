#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    FILE *intermediate, *optab, *symtab, *length, *object, *listing;
    char label[20], opcode[20], operand[20];
    char optab_code[20], optab_addr[20];
    char sym_label[20], sym_addr[20];
    char object_code[30] = "";
    int locctr, start_addr = 0, prog_length, text_len;
    bool opcode_found, sym_found;

    intermediate = fopen("intermediate.txt", "r");
    optab = fopen("optab.txt", "r");
    symtab = fopen("symtab.txt", "r");
    length = fopen("length.txt", "r");
    object = fopen("object_program.txt", "w+");
    listing = fopen("listing.txt", "w");

    if (!intermediate || !optab || !symtab || !length || !object || !listing) {
        printf("Error: Could not open one or more files.\n");
        return 1;
    }

    fscanf(length, "%d", &prog_length);
    fscanf(intermediate, "%s %s %s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        start_addr = (int)strtol(operand, NULL, 16);
        fprintf(object, "H^%s^%06X^%06X \n", label, start_addr, prog_length);
        fprintf(listing, "\t%s \t%s \t%s \n", label, opcode, operand);
        fscanf(intermediate, "%04X %s %s %s", &locctr, label, opcode, operand);
    }

    // --- Begin first text record ---
    text_len = 0;
    long text_len_pos = ftell(object);
    fprintf(object, "T^%06X^00", locctr);  // placeholder for length-00

    // --- Main loop ---
    while (strcmp(opcode, "END") != 0) {
        strcpy(object_code, "");
        opcode_found = false;

        rewind(optab);
        while (fscanf(optab, "%s %s", optab_code, optab_addr) == 2) {
            if (strcmp(optab_code, opcode) == 0) {
                opcode_found = true;
                break;
            }
        }

        if (opcode_found) {
            char operand_addr[10] = "0000";
            if (strcmp(operand, "**") != 0) {
                rewind(symtab);
                sym_found = false;
                while (fscanf(symtab, "%s %s", sym_label, sym_addr) == 2) {
                    if (strcmp(sym_label, operand) == 0) {
                        strcpy(operand_addr, sym_addr);
                        sym_found = true;
                        break;
                    }
                }
                if (!sym_found)
                    printf("Error: Undefined symbol %s\n", operand);
            }
            sprintf(object_code, "%s %s", optab_addr, operand_addr);
        } 
        else if (strcmp(opcode, "BYTE") == 0) {
            if (operand[0] == 'C') {
                for (int i = 2; i < strlen(operand) - 1; i++) {
                    char temp[5];
                    sprintf(temp, "%02X", operand[i]); // two-digit hex
                    strcat(object_code, temp);
                }
            } else if (operand[0] == 'X') {
                strncpy(object_code, operand + 2, strlen(operand) - 3);
                object_code[strlen(operand) - 3] = '\0';
            }
        } 
        else if (strcmp(opcode, "WORD") == 0) {
            sprintf(object_code, "%06X", atoi(operand));
        }

        // --- Manage text record size (max 30 bytes) ---
        if (strlen(object_code) > 0) {
            int next_len = text_len + (strlen(object_code) / 2);
            if (next_len > 30) {
                // Close current record by writing its length
                long curr_pos = ftell(object);
                fseek(object, text_len_pos + 9, SEEK_SET);
                fprintf(object, "%02X", text_len);
                fseek(object, curr_pos, SEEK_SET);
                fprintf(object, "\nT^%06X^00", locctr);  // new record
                text_len_pos = ftell(object);
                text_len = 0;
            }
            fprintf(object, "^%s", object_code);
            text_len += strlen(object_code) / 2;
        }

        // --- Write listing line ---
        fprintf(listing, "%04X \t%s \t%s \t%s \t%s \n", locctr, label, opcode, operand, object_code);

        // --- Read next line (simplified) ---
        fscanf(intermediate, "%04X %s %s %s", &locctr, label, opcode, operand);
    }

    // --- Finalize the last text record ---
    long curr_pos = ftell(object);
    fseek(object, text_len_pos + 9, SEEK_SET);
    fprintf(object, "%02X", text_len);
    fseek(object, curr_pos, SEEK_SET);

    // --- END record ---
    fprintf(listing, "%04X \t%s \t%s \t%s\n", locctr, label, opcode, operand);
    fprintf(object, "\nE^%06X \n", start_addr);

    fclose(intermediate);
    fclose(optab);
    fclose(symtab);
    fclose(length);
    fclose(object);
    fclose(listing);

    printf("Pass 2 completed.\n");
    return 0;
}
