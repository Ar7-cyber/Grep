#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Simple function to check if a string contains another string (case insensitive)
int contains_case_insensitive(const char *line, const char *term) {
    char line_copy[MAX_LINE_LENGTH];
    char term_copy[MAX_LINE_LENGTH];
    
    // Copy strings
    strcpy(line_copy, line);
    strcpy(term_copy, term);
    
    // Convert both to lowercase
    for (int i = 0; line_copy[i]; i++) {
        line_copy[i] = tolower(line_copy[i]);
    }
    
    for (int i = 0; term_copy[i]; i++) {
        term_copy[i] = tolower(term_copy[i]);
    }
    
    // Check if term exists in line
    return strstr(line_copy, term_copy) != NULL;
}

// Count how many times a term appears in a line
int count_matches(const char *line, const char *term, int case_sensitive) {
    int count = 0;
    char line_copy[MAX_LINE_LENGTH];
    char term_copy[MAX_LINE_LENGTH];
    char *position;
    
    // If case sensitive, use original strings
    if (case_sensitive) {
        strcpy(line_copy, line);
        strcpy(term_copy, term);
    } 
    // If case insensitive, convert to lowercase
    else {
        strcpy(line_copy, line);
        strcpy(term_copy, term);
        
        for (int i = 0; line_copy[i]; i++) {
            line_copy[i] = tolower(line_copy[i]);
        }
        
        for (int i = 0; term_copy[i]; i++) {
            term_copy[i] = tolower(term_copy[i]);
        }
    }
    
    // Find and count all occurrences
    position = line_copy;
    while ((position = strstr(position, term_copy)) != NULL) {
        count++;
        position++; // Move past the current match
    }
    
    return count;
}

int main() {
    char filename[256];
    char search_term[256];
    char case_choice[10];
    int case_sensitive = 1; // Default: case sensitive
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int total_matches = 0;
    int found_any = 0;
    
    // Get user input
    printf("Enter filename to search: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline
    
    printf("Enter search term: ");
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = 0; // Remove newline
    
    printf("Case-sensitive search? (yes/no): ");
    fgets(case_choice, sizeof(case_choice), stdin);
    case_choice[strcspn(case_choice, "\n")] = 0; // Remove newline
    
    // Check case sensitivity choice
    if (strcmp(case_choice, "no") == 0 || strcmp(case_choice, "NO") == 0 || 
        strcmp(case_choice, "No") == 0 || strcmp(case_choice, "n") == 0) {
        case_sensitive = 0;
    }
    
    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    
    // Process each line
    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        
        // Check if line contains the search term
        int contains;
        if (case_sensitive) {
            contains = strstr(line, search_term) != NULL;
        } else {
            contains = contains_case_insensitive(line, search_term);
        }
        
        // If found, print the line and count occurrences
        if (contains) {
            int line_matches = count_matches(line, search_term, case_sensitive);
            printf("Line %d: %s", line_number, line);
            printf("Occurrences in line: %d\n", line_matches);
            total_matches += line_matches;
            found_any = 1;
        }
    }
    
    // Print summary
    if (found_any) {
        printf("\nTotal occurrences of \"%s\": %d\n", search_term, total_matches);
    } else {
        printf("No matches found for \"%s\" in %s.\n", search_term, filename);
    }
    
    fclose(file);
    return 0;
}