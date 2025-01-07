#include <stdio.h>
#include <string.h>
void copy_word(char* word_one,char* word_two){
    int iterator=0;
    while(word_two[iterator]!='\0'){
        word_one[iterator]=word_two[iterator];
        iterator++;
    }
    word_one[iterator]='\0';
}
void finding_second_largest_word(char *input_sentence,char* result){
    int curr_len=0;
    int max_len=0;
    int second_max_len=0;
    char word[100]="";
    char first_largest_word[100]="";
    char second_largest_word[100]="";
    int sentence_iterator=0;
    int word_iterator=0;
    while(1){
        if(input_sentence[sentence_iterator]==' ' || input_sentence[sentence_iterator]=='\0'){
            if(curr_len>0){
                word[word_iterator]='\0';
                if(curr_len>max_len){
                    second_max_len=max_len;
                    max_len=curr_len;
                    copy_word(second_largest_word,first_largest_word);
                    copy_word(first_largest_word,word);
                }
                else if(curr_len>second_max_len && curr_len<max_len){
                    second_max_len=curr_len;
                    copy_word(second_largest_word,word);
                }
            }
            curr_len=0;
            word_iterator=0;
            if(input_sentence[sentence_iterator]=='\0')
                break;
        }
        else{
            word[word_iterator++]=input_sentence[sentence_iterator];
            curr_len++;
        }
        sentence_iterator++;
    }
    if(second_max_len>0)
        copy_word(result,second_largest_word);
    else
        result[0]='\0';
}
int main()
{
    char input_sentence[100];
    char second_largest_word[100];
    printf("\nInput a sentence: ");
    fgets(input_sentence,sizeof(input_sentence),stdin);
    input_sentence[strcspn(input_sentence,"\n")]='\0';
    printf("Sentence is : %s\n",input_sentence);
    finding_second_largest_word(input_sentence,second_largest_word);
    if(second_largest_word[0]!='\0')
        printf("Second Largest word is: %s",second_largest_word);
    else
        printf("Second largest word not found.");
    return 0;
}