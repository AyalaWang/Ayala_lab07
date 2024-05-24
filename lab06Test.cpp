#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "WordCount.h"
#include "tddFuncs.h"
using namespace std; 

int main() { 
    WordCount* w = new WordCount(); 
    int a = w->getTotalWords();
    cout << a << endl; 
    assertEquals("ayala", WordCount::makeValidWord("---ayala---"), "hi", __LINE__);
    assertEquals("ay'ala", WordCount::makeValidWord("---ay'ala-'''''-"), "hi", __LINE__);
    assertEquals("ay'a--la", WordCount::makeValidWord("0--13-a000y'a--$$$$la-''$''-$$$"), "hi", __LINE__);

    //w->incrWordCount("ayala");
    //assertEquals(1, w->getWordCount("ayala"), "hi", __LINE__);
    //assertEquals(1, w->getTotalWords(), "hi", __LINE__);

    //w->decrWordCount("ayala");
    //assertEquals(0, w->getWordCount("ayala"), "hi", __LINE__);
    //assertEquals(0, w->getTotalWords(), "hi", __LINE__);

    w->addAllWords("Hi, My name is Ayala Wang   $$$$$$$");
    w->addAllWords("Ayala   is  very        \n handsome :)");

    assertEquals(2, w->getWordCount("ayala"), "hi", __LINE__);
    assertEquals(2, w->getWordCount("is"), "hi", __LINE__);
    assertEquals(1, w->getWordCount("very"), "hi", __LINE__);
    assertEquals(1, w->getWordCount("handsome"), "hi", __LINE__);

    //w->dumpWordsSortedByOccurence(std::cout);

    w->dumpWordsSortedByWord(std::cout);
    cout << "--------------------------" << endl;
    w->dumpWordsSortedByOccurence(std::cout);

    assertEquals(10, w->getTotalWords(), "hi", __LINE__);
    assertEquals(2, w->getWordCount("ayala"), "hi", __LINE__);

    return 0; 
}