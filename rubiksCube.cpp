#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "Stopwatch.hpp"
using namespace std;
//AP Computer Science Principles Task
//{{Orange},{Green},{Red},{Blue},{White(top)},{Yellow(bottom)}} <-- Cube Data Structure
//{0,1,2,3,4,5,6,7,8}
//Colors: 3->🔴,4->🔵,1->🟠,2->🟢,6->🟡,5->⚪
/* OG Schema:
NOTE: White & Yelllow contain 7 blank spacing from newline
       ⚪⚪⚪
       ⚪⚪⚪
       ⚪⚪⚪
🟠🟠🟠🟢🟢🟢🔴🔴🔴🔵🔵🔵
🟠🟠🟠🟢🟢🟢🔴🔴🔴🔵🔵🔵
🟠🟠🟠🟢🟢🟢🔴🔴🔴🔵🔵🔵
       🟡🟡🟡
       🟡🟡🟡
       🟡🟡🟡
*/
void displayOriginalCube () {
    std::cout << "Original State of Cube:\n";
    for (int i=1;i<=9;i++) {
        if (i<=3) {
            std::printf("      ⚪⚪⚪\n");
        }
        if (i>3&&i<=6) {
            std::printf("🟠🟠🟠");
            std::printf("🟢🟢🟢");
            std::printf("🔴🔴🔴");
            std::printf("🔵🔵🔵\n");
        }
        if (i>6&&i<=9) {
            std::printf("      🟡🟡🟡\n");
        }
    }
}
std::vector<std::vector<char>> setupCube () {
    std::vector<std::vector<char>> out;
    for (int i=0;i<6;i++) {
        std::vector<char> face = {};
        switch (i) {
            case 0:
                for (int j=0;j<9;j++) {
                    face.push_back('o');
                }
                out.push_back(face);
                face.clear();
                break;
            case 1:
                for (int j=0;j<9;j++) {
                    face.push_back('g');
                }
                out.push_back(face);
                face.clear();
                break;
            case 2:
                for (int j=0;j<9;j++) {
                    face.push_back('r');
                }
                out.push_back(face);
                face.clear();
                break;
            case 3:
                for (int j=0;j<9;j++) {
                    face.push_back('b');
                }
                out.push_back(face);
                face.clear();
                break;
            case 4:
                for (int j=0;j<9;j++) {
                    face.push_back('w');
                }
                out.push_back(face);
                face.clear();
                break;
            case 5:
                for (int j=0;j<9;j++) {
                    face.push_back('y');
                }
                out.push_back(face);
                face.clear();
                break;
        }
    }
    return out;
}
std::string bindCharSymbol (char a) {
    std::map<char, std::string> char_symbol = {
        {'o',"🟠"},
        {'g',"🟢"},
        {'r',"🔴"},
        {'b',"🔵"},
        {'w',"⚪"},
        {'y',"🟡"}
    };
    return char_symbol[a];
}

void displayScrambledCube(std::vector<std::vector<char>> cur) {
    std::cout << "Final Position:\n";
    for (int i=0;i<9;i++) {
        std::string layer = "";
        if (i<3) {
            layer+="      ";
            layer+=(bindCharSymbol(cur[4][3*i+0]));
            layer+=(bindCharSymbol(cur[4][3*i+1]));
            layer+=(bindCharSymbol(cur[4][3*i+2]));
            std::cout << layer << "\n";
            layer.clear();
        }
        if (i>=3&&i<6) {
            for (int j=0;j<4;j++) {
                layer+=(bindCharSymbol(cur[j][3*(i-3)+0]));
                layer+=(bindCharSymbol(cur[j][3*(i-3)+1]));
                layer+=(bindCharSymbol(cur[j][3*(i-3)+2]));
            }
            std::cout << layer << "\n";
            layer.clear();
        }
        if (i>=6) {
            layer+="      ";
            layer+=(bindCharSymbol(cur[5][3*(i-6)+0]));
            layer+=(bindCharSymbol(cur[5][3*(i-6)+1]));
            layer+=(bindCharSymbol(cur[5][3*(i-6)+2]));
            std::cout << layer << "\n";
            layer.clear();
        }
    }
}
void right (std::vector<std::vector<char>>& x, std::string type) {
    if (type=="normal") {
        char a1=x[1][2],a2=x[1][5],a3=x[1][8];
        char b1=x[4][2],b2=x[4][5],b3=x[4][8];
        char c1=x[3][0],c2=x[3][3],c3=x[3][6];
        char d1=x[5][2],d2=x[5][5],d3=x[5][8];

        x[4][2]=a1,x[4][5]=a2,x[4][8]=a3;
        x[3][0]=b1,x[3][3]=b2,x[3][6]=b3;
        x[5][2]=c1,x[5][5]=c2,x[5][8]=c3;
        x[1][2]=d1,x[1][5]=d2,x[1][8]=d3;

        char s0=x[2][0],s1=x[2][1],s2=x[2][2];
        char s3=x[2][3],s5=x[2][5],s6=x[2][6];
        char s7=x[2][7],s8=x[2][8];

        x[2][0]=s6,x[2][1]=s7,x[2][2]=s0,x[2][3]=s5;
        x[2][5]=s3,x[2][6]=s8,x[2][7]=s1, x[2][8]=s2;
    }
    // 0 1 2
    // 3 4 5
    // 6 7 8
    if (type=="prime") {
        char a1=x[1][2],a2=x[1][5],a3=x[1][8];
        char b1=x[4][2],b2=x[4][5],b3=x[4][8];
        char c1=x[3][0],c2=x[3][3],c3=x[3][6];
        char d1=x[5][2],d2=x[5][5],d3=x[5][8];

        x[5][2]=a1,x[5][5]=a2,x[5][8]=a3;
        x[1][2]=b1,x[1][5]=b2,x[1][8]=b3;
        x[4][2]=c1,x[4][5]=c2,x[4][8]=c3;
        x[3][0]=d1,x[3][3]=d2,x[3][6]=d3;

        char s0=x[2][0],s1=x[2][1],s2=x[2][2];
        char s3=x[2][3],s5=x[2][5],s6=x[2][6];
        char s7=x[2][7],s8=x[2][8];

        x[2][0]=s2,x[2][1]=s5,x[2][2]=s8,x[2][3]=s1;
        x[2][5]=s7,x[2][6]=s0,x[2][7]=s3, x[2][8]=s6;
    }
    if (type=="two") {
        char a1=x[1][2],a2=x[1][5],a3=x[1][8];
        char b1=x[4][2],b2=x[4][5],b3=x[4][8];
        char c1=x[3][0],c2=x[3][3],c3=x[3][6];
        char d1=x[5][2],d2=x[5][5],d3=x[5][8];

        x[3][0]=a1,x[3][3]=a2,x[3][6]=a3;
        x[5][2]=b1,x[5][5]=b2,x[5][8]=b3;
        x[1][2]=c1,x[1][5]=c2,x[1][8]=c3;
        x[4][2]=d1,x[4][5]=d2,x[4][8]=d3;

        char s0=x[2][0],s1=x[2][1],s2=x[2][2];
        char s3=x[2][3],s5=x[2][5],s6=x[2][6];
        char s7=x[2][7],s8=x[2][8];

        x[2][0]=s8,x[2][1]=s7,x[2][2]=s6,x[2][3]=s5;
        x[2][5]=s3,x[2][6]=s2,x[2][7]=s1,x[2][8]=s0;
    }
}
void left (std::vector<std::vector<char>>& x, std::string type) {
    if (type=="normal") {
        char a1=x[1][0],a2=x[1][3],a3=x[1][6];
        char b1=x[4][0],b2=x[4][3],b3=x[4][6];
        char c1=x[3][2],c2=x[3][5],c3=x[3][8];
        char d1=x[5][0],d2=x[5][3],d3=x[5][6];

        x[5][0]=a1,x[5][3]=a2,x[5][6]=a3;
        x[1][0]=b1,x[1][3]=b2,x[1][6]=b3;
        x[4][0]=c1,x[4][3]=c2,x[4][6]=c3;
        x[3][2]=d1,x[3][5]=d2,x[3][8]=d3;

        char s0=x[0][0],s1=x[0][1],s2=x[0][2];
        char s3=x[0][3],s5=x[0][5],s6=x[0][6];
        char s7=x[0][7],s8=x[0][8];

        x[0][0]=s6,x[0][1]=s3,x[0][2]=s0,x[0][3]=s7;
        x[0][5]=s1,x[0][6]=s8,x[0][7]=s5,x[0][8]=s2;
    }

    if (type=="prime") {
        char a1=x[1][0],a2=x[1][3],a3=x[1][6];
        char b1=x[4][0],b2=x[4][3],b3=x[4][6];
        char c1=x[3][2],c2=x[3][5],c3=x[3][8];
        char d1=x[5][0],d2=x[5][3],d3=x[5][6];

        x[5][0]=c1,x[5][3]=c2,x[5][6]=c3;
        x[1][0]=d1,x[1][3]=d2,x[1][6]=d3;
        x[4][0]=a1,x[4][3]=a2,x[4][6]=a3;
        x[3][2]=b1,x[3][5]=b2,x[3][8]=b3;

        char s0=x[0][0],s1=x[0][1],s2=x[0][2];
        char s3=x[0][3],s5=x[0][5],s6=x[0][6];
        char s7=x[0][7],s8=x[0][8];

        x[0][0]=s2,x[0][1]=s5,x[0][2]=s8,x[0][3]=s1;
        x[0][5]=s7,x[0][6]=s0,x[0][7]=s3,x[0][8]=s6;
    }
    if (type=="two") {
        char a1=x[1][0],a2=x[1][3],a3=x[1][6];
        char b1=x[4][0],b2=x[4][3],b3=x[4][6];
        char c1=x[3][2],c2=x[3][5],c3=x[3][8];
        char d1=x[5][0],d2=x[5][3],d3=x[5][6];

        x[3][2]=a1,x[3][5]=a2,x[3][8]=a3;
        x[5][0]=b1,x[5][3]=b2,x[5][6]=b3;
        x[1][0]=c1,x[1][3]=c2,x[1][6]=c3;
        x[4][0]=d1,x[4][3]=d2,x[4][6]=d3;

        char s0=x[0][0],s1=x[0][1],s2=x[0][2];
        char s3=x[0][3],s5=x[0][5],s6=x[0][6];
        char s7=x[0][7],s8=x[0][8];

        x[0][0]=s8,x[0][1]=s7,x[0][2]=s6,x[0][3]=s5;
        x[0][5]=s3,x[0][6]=s2,x[0][7]=s1,x[0][8]=s0;
    }
}
void up (std::vector<std::vector<char>>& x, std::string type) {
    //swap of 0, 1, 2, 3
    if (type=="prime") {
        char a1=x[0][0],a2=x[0][1],a3=x[0][2];
        char b1=x[1][0],b2=x[1][1],b3=x[1][2];
        char c1=x[2][0],c2=x[2][1],c3=x[2][2];
        char d1=x[3][0],d2=x[3][1],d3=x[3][2];

        x[2][0]=b1,x[2][1]=b2,x[2][2]=b3;
        x[0][0]=d1,x[0][1]=d2,x[0][2]=d3;
        x[1][0]=a1,x[1][1]=a2,x[1][2]=a3;
        x[3][0]=c1,x[3][1]=c2,x[3][2]=c3;

        char s0=x[4][0],s1=x[4][1],s2=x[4][2];
        char s3=x[4][3],s5=x[4][5],s6=x[4][6];
        char s7=x[4][7],s8=x[4][8];

        x[4][0]=s2,x[4][1]=s5,x[4][2]=s8,x[4][3]=s1;
        x[4][5]=s7,x[4][6]=s0,x[4][7]=s3,x[4][8]=s6;
    }
    // 0 1 2
    // 3 4 5
    // 6 7 8
    if (type=="normal") {
        char a1=x[0][0],a2=x[0][1],a3=x[0][2];
        char b1=x[1][0],b2=x[1][1],b3=x[1][2];
        char c1=x[2][0],c2=x[2][1],c3=x[2][2];
        char d1=x[3][0],d2=x[3][1],d3=x[3][2];

        x[2][0]=d1,x[2][1]=d2,x[2][2]=d3;
        x[0][0]=b1,x[0][1]=b2,x[0][2]=b3;
        x[1][0]=c1,x[1][1]=c2,x[1][2]=c3;
        x[3][0]=a1,x[3][1]=a2,x[3][2]=a3;

        char s0=x[4][0],s1=x[4][1],s2=x[4][2];
        char s3=x[4][3],s5=x[4][5],s6=x[4][6];
        char s7=x[4][7],s8=x[4][8];

        x[4][0]=s6,x[4][1]=s3,x[4][2]=s0,x[4][3]=s7;
        x[4][5]=s1,x[4][6]=s8,x[4][7]=s5,x[4][8]=s2;
    }
    if (type=="two") {
        char a1=x[0][0],a2=x[0][1],a3=x[0][2];
        char b1=x[1][0],b2=x[1][1],b3=x[1][2];
        char c1=x[2][0],c2=x[2][1],c3=x[2][2];
        char d1=x[3][0],d2=x[3][1],d3=x[3][2];

        x[2][0]=a1,x[2][1]=a2,x[2][2]=a3;
        x[0][0]=c1,x[0][1]=c2,x[0][2]=c3;
        x[1][0]=d1,x[1][1]=d2,x[1][2]=d3;
        x[3][0]=b1,x[3][1]=b2,x[3][2]=b3;

        char s0=x[4][0],s1=x[4][1],s2=x[4][2];
        char s3=x[4][3],s5=x[4][5],s6=x[4][6];
        char s7=x[4][7],s8=x[4][8];

        x[4][0]=s8,x[4][1]=s7,x[4][2]=s6,x[4][3]=s5;
        x[4][5]=s3,x[4][6]=s2,x[4][7]=s1,x[4][8]=s0;
    }
}
void down (std::vector<std::vector<char>>& x, std::string type) {
    if (type=="normal") {
        char a1=x[0][6],a2=x[0][7],a3=x[0][8];
        char b1=x[1][6],b2=x[1][7],b3=x[1][8];
        char c1=x[2][6],c2=x[2][7],c3=x[2][8];
        char d1=x[3][6],d2=x[3][7],d3=x[3][8];

        x[2][6]=b1,x[2][7]=b2,x[2][8]=b3;
        x[0][6]=d1,x[0][7]=d2,x[0][8]=d3;
        x[1][6]=a1,x[1][7]=a2,x[1][8]=a3;
        x[3][6]=c1,x[3][7]=c2,x[3][8]=c3;

        char s0=x[5][0],s1=x[5][1],s2=x[5][2];
        char s3=x[5][3],s5=x[5][5],s6=x[5][6];
        char s7=x[5][7],s8=x[5][8];

        x[5][0]=s6,x[5][1]=s3,x[5][2]=s0,x[5][3]=s7;
        x[5][5]=s1,x[5][6]=s8,x[5][7]=s5,x[5][8]=s2;
    }
    if (type=="prime") {
        char a1=x[0][6],a2=x[0][7],a3=x[0][8];
        char b1=x[1][6],b2=x[1][7],b3=x[1][8];
        char c1=x[2][6],c2=x[2][7],c3=x[2][8];
        char d1=x[3][6],d2=x[3][7],d3=x[3][8];

        x[2][6]=d1,x[2][7]=d2,x[2][8]=d3;
        x[0][6]=b1,x[0][7]=b2,x[0][8]=b3;
        x[1][6]=c1,x[1][7]=c2,x[1][8]=c3;
        x[3][6]=a1,x[3][7]=a2,x[3][8]=a3;

        char s0=x[5][0],s1=x[5][1],s2=x[5][2];
        char s3=x[5][3],s5=x[5][5],s6=x[5][6];
        char s7=x[5][7],s8=x[5][8];

        x[5][0]=s2,x[5][1]=s5,x[5][2]=s8,x[5][3]=s1;
        x[5][5]=s7,x[5][6]=s0,x[5][7]=s3,x[5][8]=s6;
    }
    if (type=="two") {
        char a1=x[0][6],a2=x[0][7],a3=x[0][8];
        char b1=x[1][6],b2=x[1][7],b3=x[1][8];
        char c1=x[2][6],c2=x[2][7],c3=x[2][8];
        char d1=x[3][6],d2=x[3][7],d3=x[3][8];

        x[2][6]=a1,x[2][7]=a2,x[2][8]=a3;
        x[0][6]=c1,x[0][7]=c2,x[0][8]=c3;
        x[1][6]=d1,x[1][7]=d2,x[1][8]=d3;
        x[3][6]=b1,x[3][7]=b2,x[3][8]=b3;

        char s0=x[5][0],s1=x[5][1],s2=x[5][2];
        char s3=x[5][3],s5=x[5][5],s6=x[5][6];
        char s7=x[5][7],s8=x[5][8];

        x[5][0]=s8,x[5][1]=s7,x[5][2]=s6,x[5][3]=s5;
        x[5][5]=s3,x[5][6]=s2,x[5][7]=s1,x[5][8]=s0;
    }
}

void normalF (std::vector<std::vector<char>>& x) {
    char a1=x[0][2],a2=x[0][5],a3=x[0][8];
    char b1=x[2][0],b2=x[2][3],b3=x[2][6];
    char c1=x[4][6],c2=x[4][7],c3=x[4][8];
    char d1=x[5][0],d2=x[5][1],d3=x[5][2];

    x[0][2]=d1,x[0][5]=d2,x[0][8]=d3;
    x[2][0]=c1,x[2][3]=c2,x[2][6]=c3;
    x[4][6]=a3,x[4][7]=a2,x[4][8]=a1;
    x[5][0]=b3,x[5][1]=b2,x[5][2]=b1;

    char s0=x[1][0],s1=x[1][1],s2=x[1][2];
    char s3=x[1][3],s5=x[1][5],s6=x[1][6];
    char s7=x[1][7],s8=x[1][8];

    x[1][0]=s6,x[1][1]=s7,x[1][2]=s0,x[1][3]=s5;
    x[1][5]=s3,x[1][6]=s8,x[1][7]=s1,x[1][8]=s2;
}

void front (std::vector<std::vector<char>>& x, std::string type) {
    if (type=="normal") {
        normalF(x);
    }
    if (type=="prime") {
        normalF(x);
        normalF(x);
        normalF(x);
    }
    if (type=="two") {
        normalF(x);
        normalF(x);
    }
}



//Colors: 3->🔴,4->🔵,1->🟠,2->🟢,6->🟡,5->⚪
/* OG Schema:
NOTE: White & Yelllow contain 7 blank spacing from newline
       ⚪⚪⚪
       ⚪⚪⚪
       ⚪⚪⚪
🟠🟠🟠🟢🟢🟢🔴🔴🔴🔵🔵🔵
🟠🟠🟠🟢🟢🟢🔴🔴🔴🔵🔵🔵
🟠🟠🟠🟢🟢🟢🔴🔴🔴🔵🔵🔵
       🟡🟡🟡
       🟡🟡🟡
       🟡🟡🟡
*/

void normalBP (std::vector<std::vector<char>>& x) {
    char a1=x[0][2],a2=x[0][5],a3=x[0][8];
    char b1=x[2][0],b2=x[2][3],b3=x[2][6];
    char c1=x[4][6],c2=x[4][7],c3=x[4][8];
    char d1=x[5][0],d2=x[5][1],d3=x[5][2];

    x[0][2]=d1,x[0][5]=d2,x[0][8]=d3;
    x[2][0]=c1,x[2][3]=c2,x[2][6]=c3;
    x[4][6]=a3,x[4][7]=a2,x[4][8]=a1;
    x[5][0]=b3,x[5][1]=b2,x[5][2]=b1;

    char s0=x[3][0],s1=x[3][1],s2=x[3][2];
    char s3=x[3][3],s5=x[3][5],s6=x[3][6];
    char s7=x[3][7],s8=x[3][8];

    x[3][0]=s6,x[3][1]=s7,x[3][2]=s0,x[3][3]=s5;
    x[3][5]=s3,x[3][6]=s8,x[3][7]=s1,x[3][8]=s2;
}

void back (std::vector<std::vector<char>>& x, std::string type) {
    if (type=="normal") {
        normalBP(x);
        normalBP(x);
        normalBP(x);
    }
    if (type=="prime") {
        normalBP(x);
    }
    if (type=="two") {
        normalBP(x);
        normalBP(x);
    }
}

bool validateInput (std::vector<std::string> in) {
    std::vector<std::string> valid = {"R","R\'","R2","L","L\'","L2","U","U\'","U2","D","D\'","D2","F","F\'","F2","B","B\'","B2"};
    int correct = 1;
    for (auto j : in) {
        bool found = (std::find(valid.begin(), valid.end(), j) != valid.end());
        if (!found) {
            correct*=0;
        }
    }
    if (correct == 1) {
        return true;
    } else {
        return false;
    }
}
std::vector<std::string> splitInput (std::string in) {
    std::vector<std::string> out = {};
    std::string cur = "";
    for (auto i : in) {
        if (i==' ') {
            out.push_back(cur);
            cur.clear();
        } else {
            cur+=i;
        }
    }
    return out;
}

std::string generateScramble () {
    std::vector<std::string> moves = {"R","R\'","R2","L","L\'","L2","U","U\'","U2","D","D\'","D2","F","F\'","F2","B","B\'","B2"};
    std::string scramble = "";
    int prevVal = 0;
    srand((unsigned) time(0));
    for (int i=0;i<23;i++) {
        int a=(rand()%6);
        if (a==prevVal) {
            a=(a+1)%6;
        }
        prevVal=a;
        int b=(rand()%3);
        scramble+=moves[a*3+b];
        scramble+=" ";
    }
	return scramble;
}

bool runAgain () {
    bool out = false;
    std::string exit;
    std::cout << "Do you want to run this program again?\n> ";
    std::cin >> exit;
    if (exit=="y") {
        out = false;
    } else if (exit=="n") {
        out = true;
    } else {
        std::printf("INVALID INPUT\n");
    }
    return out;
}

std::vector<std::string> splitBy (std::string message, char split) {
        std::string temp;
        std::vector<std::string> out;
        for (int i=0; i<(int)message.size(); i++){
            if (message[i]!=split) {
                temp += message[i];
            } else {
                out.push_back(temp);
                temp="";
            }
        }
        out.push_back(temp);
        return out;
    }

void actions (std::vector<std::vector<char>>& cube, std::string scramble) {
    std::vector<std::string> scrambe = splitBy(scramble,' ');
    for (auto j : scrambe) {
        if (j[0]=='R') {
            if (j.length()==1) {
                right(cube,"normal");
            } else if (j[1]=='2') {
                right(cube,"two");
            } else {
                right(cube,"prime");
            }
        }
        if (j[0]=='L') {
            if (j.length()==1) {
                left(cube,"normal");
            } else if (j[1]=='2') {
                left(cube,"two");
            } else {
                left(cube,"prime");
            }
        }
        if (j[0]=='U') {
            if (j.length()==1) {
                up(cube,"normal");
            } else if (j[1]=='2') {
                up(cube,"two");
            } else {
                up(cube,"prime");
            }
        }
        if (j[0]=='D') {
            if (j.length()==1) {
                down(cube,"normal");
            } else if (j[1]=='2') {
                down(cube,"two");
            } else {
                down(cube,"prime");
            }
        }
        if (j[0]=='F') {
            if (j.length()==1) {
                front(cube,"normal");
            } else if (j[1]=='2') {
                front(cube,"two");
            } else {
                front(cube,"prime");
            }
        }
        if (j[0]=='B') {
            if (j.length()==1) {
                back(cube,"normal");
            } else if (j[1]=='2') {
                back(cube,"two");
            } else {
                back(cube,"prime");
            }
        }
    }
}

int main () {
    std::string scrambe = generateScramble();
    std::cout << scrambe << std::endl;
    SetConsoleOutputCP(CP_UTF8);
    displayOriginalCube();
    std::vector<std::vector<char>> x = setupCube();
    actions(x,scrambe);
    displayScrambledCube(x);
    std::cout << "Press (space) to start and stop timer\n";
    getch();
    namespace sw = stopwatch;
    sw::Stopwatch my_watch;
    getch();
    auto duration_ms = my_watch.elapsed();
    std::cout << "Time: " << (duration_ms+0.0)/1000 << " sec" << std::endl;
    return 0;
}


//DOUBLED FUNCTIONS WORKING: R2, L2, U2, D2, F2, B2
//REGULAR FUNCTIONS WORKING: R, R', L, L', U, U', D, D', F, F', B, B'
