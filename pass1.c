#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    FILE *source, *optab, *intermediate, *symtab, *length;
    char label[20], opcode[20], operand[20], symtab_data[20], optab_data[20];
    int locctr, starting_address, program_length;
    bool symbol_found, opcode_found;

    source = fopen("source.txt", "r");
    optab = fopen("optab.txt", "r");
    intermediate = fopen("intermediate.txt", "w");
    symtab = fopen("symtab.txt", "w+");
    length = fopen("length.txt", "w");

    fscanf(source, "%s %s %s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0) {
        starting_address = (int)strtol(operand, NULL, 16);
        locctr = starting_address;
        fprintf(intermediate, "\t%s \t%s \t%s \n", label, opcode, operand);
        fscanf(source, "%s %s %s", label, opcode, operand);
    } else {
        locctr = 0;
    }

    while (strcmp(opcode, "END") != 0) {
        fprintf(intermediate, "%04X \t%s \t%s \t%s \n", locctr, label, opcode, operand);
      
        if (strcmp(label, "**") != 0) {
            symbol_found = false;
            rewind(symtab);
            while (fscanf(symtab, "%s", symtab_data) == 1) {
                if (strcmp(symtab_data, label) == 0) {
                    printf("Error: Duplicate symbol found: %s\n", label);
                    symbol_found = true;
                    break;
                }
            }
            if (!symbol_found) {
                fprintf(symtab, "%s\t%04X\n", label, locctr);
            }
        }

        opcode_found = false;
        rewind(optab);
        while (fscanf(optab, "%s", optab_data) == 1) {
            if (strcmp(optab_data, opcode) == 0) {
                opcode_found = true;
                break;
            }
        }

        if (opcode_found) {
            locctr += 3;
        } else if (strcmp(opcode, "WORD") == 0) {
            locctr += 3;
        } else if (strcmp(opcode, "RESW") == 0) {
            locctr += 3 * atoi(operand);
        } else if (strcmp(opcode, "RESB") == 0) {
            locctr += atoi(operand);
        } else if (strcmp(opcode, "BYTE") == 0) {
            if (operand[0] == 'C') {
                locctr += (int)strlen(operand) - 3;
            } else if (operand[0] == 'X') {
                locctr += ((int)strlen(operand) - 3) / 2;
            }
        } else {
            printf("Error: Invalid opcode: %s\n", opcode);
        }
      
        fscanf(source, "%s %s %s", label, opcode, operand);
    }

    fprintf(intermediate, "%04X \t%s \t%s \t%s \n", locctr, label, opcode, operand);

    program_length = locctr - starting_address;
    printf("\nProgram length: %d\n", program_length);
    fprintf(length, "%04X", program_length);

    fclose(source);
    fclose(optab);
    fclose(intermediate);
    fclose(symtab);
    fclose(length);
    
    return 0;
}
