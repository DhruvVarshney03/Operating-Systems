/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

int main() {
    int pageRequests[MAX_PAGES];
    int pageFrames[MAX_FRAMES];
    int pageFaults = 0;
    int n, m, i, j, k, max, idx;

    printf("Enter the number of page requests: ");
    scanf("%d", &n);

    printf("Enter the page requests: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pageRequests[i]);
    }

    printf("Enter the number of page frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        pageFrames[i] = -1;
    }

    for(i = 0; i < n; i++) {
        int page = pageRequests[i];
        int found = 0;

        for(j = 0; j < m; j++) {
            if(pageFrames[j] == page) {
                found = 1;
                break;
            }
        }

        if(!found) {
            pageFaults++;

            if(i < m) {
                pageFrames[i] = page;
            }
            else {
                int next[MAX_FRAMES] = {0};
                for(j = 0; j < m; j++) {
                    for(k = i + 1; k < n; k++) {
                        if(pageFrames[j] == pageRequests[k]) {
                            next[j] = k;
                            break;
                        }
                        next[j] = n;
                    }
                }
                max = next[0];
                idx = 0;
                for(j = 1; j < m; j++) {
                    if(next[j] > max) {
                        max = next[j];
                        idx = j;
                    }
                }
                pageFrames[idx] = page;
            }
        }
    }

    printf("Number of page faults: %d\n", pageFaults);
    printf("Number of page hits: %d\n", n-pageFaults);
    return 0;
}

