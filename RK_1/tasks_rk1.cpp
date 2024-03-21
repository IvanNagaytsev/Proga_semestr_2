#include <iostream>

using namespace std;

void buildTree(int height, int shift, int rotate);

void fill_layer(int a, int b, char** matrix, int layer, int length);

void fill_matrix(int height, int shift, int rotate, char** matrix);

void print_matrix(int height, int shift, char** matrix);

int main()
{
    int height, shift, rotate;
    printf("Enter height: ");
    scanf("%d", &height);
    printf("Enter shift: ");
    scanf("%d", &shift);
    printf("Enter rotate: ");
    scanf("%d", &rotate);
    buildTree(height, shift, rotate);
    return 0;
}

void buildTree(int height, int shift, int rotate)
{
    char** matrix = new char* [shift+height];
    for(int i = 0; i<shift+height; i++)
        matrix[i] = new char [2*height];
    for(int i = 0; i<shift+height; i++)
        for(int j = 0; j<2*height; j++)
            matrix[i][j] = ' ';
    fill_matrix(height, shift, ((rotate)/90)%4, matrix);
    print_matrix(height, shift, matrix);

}

void fill_matrix(int height, int shift, int rotate, char** matrix)
{
    int k = 0;
    switch (rotate)
    {
    case 0:
        for(int i = 0; i<height; i++)
        {
            if(shift < height - 1)
                fill_layer(shift - 1 - k, 1 + k, matrix, i, shift+height-1);
            if(shift >= height - 1)
                fill_layer(shift - 1 - k, 1 + 2*k, matrix, i, shift+height-1);
            k++;
        }
        break;
    case 1:
        for(int i = 0; i<2*height-1; i++)
        {
            if(k > height)
                fill_layer(shift - 1, 2*height - k, matrix, i, shift+height-1);
            if(k <= height)
                fill_layer(shift - 1 - k, 1 + k, matrix, i, shift+height-1);
            k++;
        }
        break;
    case 2:
        k = height;
        for(int i = 0; i<height; i++)
        {
            if(shift < height - 1)
                fill_layer(shift - 1 - k, 1 + k, matrix, i, shift+height-1);
            if(shift >= height - 1)
                fill_layer(shift - 1 - k, 1 + 2*k, matrix, i, shift+height-1);
            k--;
        }
        break;
    case 3:
        break;
    }
}

void fill_layer(int a, int b, char** matrix, int layer, int length)
{
    for(int i = 0; i<a; i++)
        matrix[layer][i] = ' ';
    for(int i = 0; i<b; i++)
        matrix[layer][i+a] = '*';
    for(int i = 0; i<length;i++)
        matrix[layer][i+a+b] = ' ';
}

void print_matrix(int height, int shift, char** matrix)
{
    for(int i = 0; i<2*height-1; i++)
    {
        for(int j = 0; j<shift+height; j++)
            printf("%c", matrix[i][j]);
        puts("");
    }
}
