#include <stdio.h>



int main() {

    int n , m, k;
    scanf ("%d", &n);
    scanf ("%d", &m);
    scanf ("%d", &k);

    char array_of_strings [n][m];
    char help [m];

    for (int i = 0; i < n; ++i) {
        scanf("%s", &array_of_strings[i]);
    }
    //printf("%d", 'a' - 97 ); //26 liter
    //printf("kk %c\n", array_of_strings[0][1]);
    //radixSort
    int c [26];
    char b[n][m];
    int d, count, tmp;
    for (int i = m - 1; i > -1; i--) {
        if (k == 0){
            break;
        }
        for (int j = 0; j < 26; j++){
            c[j] = 0;
        }
        for (int j = 0; j < n; j++){
            d = (int) array_of_strings[j][i] - 97;
            c[d]++;
        }
        count = 0;
        for (int j = 0; j < 26; j++){
            tmp = c[j];
            c[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; j++){
            d = (int) array_of_strings[j][i] - 97;
            for (int p = 0; p < m; p++) {
                b[c[d]][p] = array_of_strings[j][p];
            }
            c[d]++;
        }
        for (int j = 0; j < n; j++){
            for (int p = 0; p < m; p++) {
                array_of_strings[j][p] = b[j][p];
            }
        }
        k--;
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++){
            printf("%c", array_of_strings[i][j]);
        }
        printf("\n");
    }



    return 0;
}
