/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_FRAMES 10

int main() {
    int frames[MAX_FRAMES], pages[MAX_FRAMES];
    int num_frames, num_pages, page_faults = 0, frame_index = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the page references: ");
    for(int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize all frames to -1 to indicate they are empty
    for(int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for(int i = 0; i < num_pages; i++) {
        int page = pages[i];
        int hit = 0;

        // Check if page is already in frame
        for(int j = 0; j < num_frames; j++) {
            if(frames[j] == page) {
                hit = 1;
                break;
            }
        }

        // If page is not in frame, add it to the next available slot
        if(!hit) {
            frames[frame_index] = page;
            frame_index = (frame_index + 1) % num_frames;
            page_faults++;
        }

        // Print current state of frames
        printf("Page %d: ", page);
        for(int j = 0; j < num_frames; j++) {
            if(frames[j] == -1) {
                printf(" ");
            } else {
                printf("%d", frames[j]);
            }
            printf(" ");
        }
        printf("\n");
    }
    
    int page_hit=num_pages-page_faults;
    
    
    printf("Page fault: %d\n", page_faults);
    printf("Hit: %d\n", page_hit);

    return 0;
}

