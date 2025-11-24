#include<stdio.h>
#include<ctype.h>

char universal_set[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char set1[26],set2[26];
int bit_vec1[26],bit_vec2[26],result[26];

void initializeSet()
{
    for(int i=0;i<26;i++)
    {
        bit_vec1[i]=0;
        bit_vec2[i]=0;
        result[i]=0;
    }
}

void bitVector(char ary[26],int bit[26],int num)   // FIXED: ary changed to char
{
    for(int i=0;i<num;i++)
    {
        char c = toupper(ary[i]);
        for(int j=0;j<26;j++)
        {
            if(c == universal_set[j])
                bit[j]=1;
        }
    }
}

void setunion(int bit_vec1[26],int bit_vec2[26])
{
    for(int i=0;i<26;i++)
        result[i]=bit_vec1[i] | bit_vec2[i];
}

void setintersection(int bit_vec1[26],int bit_vec2[26])
{
    for(int i=0;i<26;i++)
        result[i]=bit_vec1[i] & bit_vec2[i];
}

void setcomplement(int bit_vect[26])    // FIXED: corrected parameter name and type
{
    for(int i=0;i<26;i++)
    {
        if(bit_vect[i] == 0)
            result[i] = 1;  
        else
            result[i] = 0;
    }
}

void setdifference(int bit_vec1[26],int bit_vec2[26])
{
    int comp[26];   // FIXED: needed to store complement temporarily
    for(int i=0;i<26;i++)
        comp[i] = (bit_vec2[i] == 0) ? 1 : 0;

    for(int i=0;i<26;i++)
        result[i] = bit_vec1[i] & comp[i];
}

void printResult()
{
    printf("{ ");
    for(int i=0;i<26;i++)
    {
        if(result[i] == 1)
            printf("%c ", universal_set[i]);
    }
    printf("}\n");
}

int main()
{
    int num1,num2;
    initializeSet();

    printf("Enter the number of elements in set1:\n"); 
    scanf("%d",&num1);

    printf("Enter the set1 elements:\n");
    for(int i=0;i<num1;i++)
        scanf(" %c",&set1[i]);   // FIXED: space before %c to ignore newline

    printf("Enter the number of elements in set2:\n");
    scanf("%d",&num2);

    printf("Enter the set2 elements:\n");
    for(int i=0;i<num2;i++)
        scanf(" %c",&set2[i]);   // FIXED

    // bit vectors
    bitVector(set1,bit_vec1,num1);
    bitVector(set2,bit_vec2,num2);

    printf("\nUnion: ");
    setunion(bit_vec1,bit_vec2);
    printResult();

    printf("Intersection: ");
    setintersection(bit_vec1,bit_vec2);
    printResult();

    printf("Difference (Set1 - Set2): ");
    setdifference(bit_vec1,bit_vec2);
    printResult();

    printf("Complement of Set1: ");
    setcomplement(bit_vec1);
    printResult();

    return 0;
}

