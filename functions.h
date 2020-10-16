#define Student struct Stud

struct Stud

{

    char srn[15];

    char name[100];

    char branch[50];

    float marks[16];

    float sgpa[2];

    float cgpa;

};



void add(FILE * fp);

FILE * del(FILE * fp);

void modify(FILE * fp);

void displayList(FILE * fp);

void searchRecord(FILE *fp);

void printChar(char ch,int n);

void printHead();

