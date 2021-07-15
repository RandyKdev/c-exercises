// link to problem statement
// https://cs50.harvard.edu/x/2021/psets/2/readability/

#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#include<assert.h>

int readability(const char *phrase) {
    int c, i = 0, letters = 0, words = 1, sentences = 0;
     while((c = phrase[i++]) != '\0')
        if(isalpha(c)) letters++;
        else if(c == ' ') words++;
        else if (c == '?' || c == '.' || c == '!') sentences++;

    float lettersPer100Words = (letters / words) * 100.0;
    float sentencesPer100Words = (sentences / words) * 100.0;

    float index = (0.0588 * lettersPer100Words) - (0.296 * sentencesPer100Words) - 15.8;

    return (int) round(index);
}

void test() {
    const char *testStrings[] = { 
        "One fish. Two fish. Red fish. Blue fish.",
        "Would you like them here or there? I would not like them here or there. I would not like them anywhere.",
        "Congratulations! Today is your day. You're off to Great Places! You're off and away!",
        "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.",
        "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.",
        "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, 'and what is the use of a book,' thought Alice 'without pictures or conversation?'",
        "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right, when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.",
        "There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.",
        "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.",
        "A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains." 
    };
    
    const int solutions[] = {-9, 2, 3, 5, 7, 8, 8, 9 , 10, 18};
    
    for(int i = 0; i < 10; i++)
        assert(readability(testStrings[i]) == solutions[i]);
}

int main(void) {

    test();

    return 0;
}