/**************************************************************
    Problem: 4020
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:228 ms
    Memory:27316 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;
 
#include<deque>
#include<set>
#include<map>
#include<sstream>
#include<vector>
 
set<string> FUNCS;
vector<int> FIN;
vector<int>::iterator FINpointer;
 
namespace Cursor
{
    // 输入流管理器
    deque<int> buffer;
    void Init()
    {
        buffer.clear();
    }
    int nxtChar()
    {
        if (buffer.size() == 0)
            buffer.push_back(getchar());
        return buffer.front();
    }
    int getChar()
    {
        int ret = nxtChar();
        buffer.pop_front();
        return ret;
    }
    bool seekEOF()
    {
        return (nxtChar() == EOF);
    }
};
 
int to_i(string s)
{
    int ret = 0, i;
    fortodo(i, 0, int(s.size()) - 1)
        ret = ret * 10 + (s[i] - '0');
    return ret;
}
 
const int TINTCONSTANT = 0;
const int TNAME = 1;
const int TSPECIAL = 2;
const int TEMPTY = 3;
const int TEOF = -1;
const char SEOF = '\n';
 
int charType(int ch)
{
    if ((ch >= '0') && (ch <= '9')) return TINTCONSTANT;
    if ((ch >= 'A') && (ch <= 'Z')) return TNAME;
    if ((ch >= 'a') && (ch <= 'z')) return TNAME;
    if (ch == '_') return TNAME;
    if ((ch == ' ') || (ch == '\n') || (ch == '\r')) return TEMPTY;
    if (ch == EOF) return TEOF;
    return TSPECIAL;
}
 
int lexemeType(string lexeme)
{
    if (lexeme[0] == SEOF) return TEOF;
    return charType(lexeme[0]);
}
 
namespace Scanner
{
    // 词法分析器
    deque<string> buffer;
    void Init()
    {
        Cursor::Init();
        buffer.clear();
    }
    string nxtLexeme()
    {
        if (buffer.size()) return buffer.front();
        while (charType(Cursor::nxtChar()) == TEMPTY) Cursor::getChar();
        if (Cursor::seekEOF())
            {
                buffer.push_back("\n");
                return "\n";
            }
        int typ = charType(Cursor::nxtChar());
        if (typ == TINTCONSTANT)
            {
                string ret = "";
                while (charType(Cursor::nxtChar()) == TINTCONSTANT)
                    ret += char(Cursor::getChar());
                buffer.push_back(ret);
                return ret;
            }
        if (typ == TNAME)
            {
                string ret = "";
                int t;
                while (((t = charType(Cursor::nxtChar())) == TINTCONSTANT) || (t == TNAME))
                    ret += char(Cursor::getChar());
                buffer.push_back(ret);
                return ret;
            }
        char ch = Cursor::nxtChar();
        if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%') || (ch == '^') || (ch == '#') || (ch == ';') || (ch == ',') || (ch == '[') || (ch == ']') || (ch == '(') || (ch == ')') || (ch == '{') || (ch == '}'))
            {
                string ret = "";
                ret += Cursor::getChar();;
                buffer.push_back(ret);
                return ret;
            }
        if ((ch == '<') || (ch == '>') || (ch == '&') || (ch == '|') || (ch == '!') || (ch == '='))
            {
                string ret = "";
                ret += char(Cursor::getChar());
                if ((Cursor::nxtChar() == ch) || (Cursor::nxtChar() == '='))
                    ret += char(Cursor::getChar());
                buffer.push_back(ret);
                return ret;
            }
        stringstream ss;
        ss.str("");
        ss << "unexpected char " << ch << " ASCII = " << int(ch);
        throw ss.str();
    }
    string getLexeme()
    {
        string ret = nxtLexeme();
        buffer.pop_front();
        return ret;
    }
    bool seekEOF()
    {
        return nxtLexeme() == "\n";
    }
};
 
struct Lexitree
{
    vector<string> A;
    vector<Lexitree*> B;
    Lexitree()
    {
        A.clear();
        B.clear();
    }
};
 
//--------------------------------------------------
// 语法分析器开始
 
void assertLexeme(string target)
{
    string ret = Scanner::getLexeme();
    if (ret != target)
        {
            stringstream ss;
            ss.str("");
            ss << "expected lexeme " << target << ", but lexeme " << ret << " found." << endl;
            throw ss.str();
        }
}
 
Lexitree* PROGRAM();
Lexitree* FUNC_AND_VAR();
vector<string> OPTPARAMS();
vector<string> PARAMS();
Lexitree* STATEMENTS();
Lexitree* STATEMENT();
Lexitree* STATEMENT_IN_FOR();
Lexitree* OPTEXPRESSION();
Lexitree* EXPRESSION();
Lexitree* UNIT0();
Lexitree* UNIT1();
Lexitree* UNIT2();
Lexitree* UNIT3();
Lexitree* UNIT4();
Lexitree* UNIT5();
Lexitree* UNIT6();
Lexitree* UNIT7();
Lexitree* UNIT8();
Lexitree* UNIT9();
vector<Lexitree*> OPTARGUS();
vector<Lexitree*> ARGUS();
Lexitree* DEFINEVAR();
vector<Lexitree*> DEFINEVARS();
string NAME();
string INT_CONSTANT();
 
Lexitree* PROGRAM()
{
    assertLexeme("#");
    assertLexeme("include");
    assertLexeme("<");
    assertLexeme("iostream");
    assertLexeme(">");
    assertLexeme("#");
    assertLexeme("include");
    assertLexeme("<");
    assertLexeme("cstdio");
    assertLexeme(">");
    assertLexeme("using");
    assertLexeme("namespace");
    assertLexeme("std");
    assertLexeme(";");
    return FUNC_AND_VAR();
}
 
Lexitree* FUNC_AND_VAR()
{
    Lexitree* cur = new Lexitree;
    while (!Scanner::seekEOF())
        {
            assertLexeme("int");
            string s = NAME();
            if (Scanner::nxtLexeme() == "(")
                {
                    cur->A.push_back("Function");
                    Lexitree* newFunc = new Lexitree;
                    newFunc->A.push_back(s);
                    FUNCS.insert(s);
                    assertLexeme("(");
                    vector<string> paraNames = OPTPARAMS();
                    newFunc->A.insert(newFunc->A.end(), paraNames.begin(), paraNames.end());
                    assertLexeme(")");
                    assertLexeme("{");
                    newFunc->B.push_back(STATEMENTS());
                    assertLexeme("}");
                    cur->B.push_back(newFunc);
                }
            else
                {
                    cur->A.push_back("int");
                    Scanner::buffer.push_front(s);
                    Lexitree* newInt = new Lexitree;
                    newInt->B.push_back(DEFINEVAR());
                    vector<Lexitree*> p = DEFINEVARS();
                    newInt->B.insert(newInt->B.end(), p.begin(), p.end());
                    assertLexeme(";");
                    cur->B.push_back(newInt);
                }
        }
    return cur;
}
 
vector<string> OPTPARAMS()
{
    vector<string> cur;
    cur.clear();
    if (Scanner::nxtLexeme() == ")") return cur;
    assertLexeme("int");
    cur.push_back(NAME());
    vector<string> p = PARAMS();
    cur.insert(cur.end(), p.begin(), p.end());
    return cur;
}
 
vector<string> PARAMS()
{
    vector<string> ret;
    ret.clear();
    while (Scanner::nxtLexeme() == ",")
        {
            assertLexeme(",");
            assertLexeme("int");
            ret.push_back(NAME());
        }
    return ret;
}
 
Lexitree* STATEMENTS()
{
    Lexitree* cur = new Lexitree;
    while (Scanner::nxtLexeme() != "}")
        cur->B.push_back(STATEMENT());
    return cur;
}
 
Lexitree* STATEMENT()
{
    Lexitree* cur = new Lexitree;
    if (Scanner::nxtLexeme() == "if")
        {
            cur->A.push_back("if");
            assertLexeme("if");
            assertLexeme("(");
            cur->B.push_back(EXPRESSION());
            assertLexeme(")");
            cur->B.push_back(STATEMENT());
            if (Scanner::nxtLexeme() == "else")
                {
                    assertLexeme("else");
                    cur->B.push_back(STATEMENT());
                }
            return cur;
        }
    if (Scanner::nxtLexeme() == "int")
        {
            cur->A.push_back("int");
            assertLexeme("int");
            cur->B.push_back(DEFINEVAR());
            vector<Lexitree*> p = DEFINEVARS();
            cur->B.insert(cur->B.end(), p.begin(), p.end());
            assertLexeme(";");
            return cur;
        }
    if (Scanner::nxtLexeme() == "{")
        {
            cur->A.push_back("{");
            assertLexeme("{");
            cur->B.push_back(STATEMENTS());
            assertLexeme("}");
            return cur;
        }
    if (Scanner::nxtLexeme() == "for")
        {
            cur->A.push_back("for");
            assertLexeme("for");
            assertLexeme("(");
            cur->B.push_back(STATEMENT_IN_FOR());
            assertLexeme(";");
            cur->B.push_back(OPTEXPRESSION());
            assertLexeme(";");
            cur->B.push_back(STATEMENT_IN_FOR());
            assertLexeme(")");
            cur->B.push_back(STATEMENT());
            return cur;
        }
    if (Scanner::nxtLexeme() == "while")
        {
            cur->A.push_back("while");
            assertLexeme("while");
            assertLexeme("(");
            cur->B.push_back(EXPRESSION());
            assertLexeme(")");
            cur->B.push_back(STATEMENT());
            return cur;
        }
    if (Scanner::nxtLexeme() == "return")
        {
            cur->A.push_back("return");
            assertLexeme("return");
            cur->B.push_back(EXPRESSION());
            assertLexeme(";");
            return cur;
        }
    cur->A.push_back("expression");
    cur->B.push_back(EXPRESSION());
    assertLexeme(";");
    return cur;
}
 
Lexitree* STATEMENT_IN_FOR()
{
    Lexitree* cur = new Lexitree;
    if ((Scanner::nxtLexeme() == ";") || (Scanner::nxtLexeme() == ")")) return cur;
    if (Scanner::nxtLexeme() == "int")
        {
            cur->A.push_back("int");
            assertLexeme("int");
            cur->B.push_back(DEFINEVAR());
            vector<Lexitree*> p = DEFINEVARS();
            cur->B.insert(cur->B.end(), p.begin(), p.end());
            return cur;
        }
    cur->A.push_back("expression");
    cur->B.push_back(EXPRESSION());
    return cur;
}
 
Lexitree* OPTEXPRESSION()
{
    Lexitree* cur = new Lexitree;
    if (Scanner::nxtLexeme() == ";") return cur;
    cur->B.push_back(EXPRESSION());
    return cur;
}
 
Lexitree* EXPRESSION()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT9());
    while ((Scanner::nxtLexeme() == "<<") || (Scanner::nxtLexeme() == ">>"))
        {
            cur->A.push_back(Scanner::getLexeme());
            cur->B.push_back(UNIT9());
        }
    return cur;
}
 
Lexitree* UNIT0()
{
    Lexitree* cur = new Lexitree;
    if ((Scanner::nxtLexeme() == "cin") || (Scanner::nxtLexeme() == "cout") || (Scanner::nxtLexeme() == "endl"))
        {
            cur->A.push_back(Scanner::getLexeme());
            return cur;
        }
    if (lexemeType(Scanner::nxtLexeme()) == TINTCONSTANT)
        {
            cur->A.push_back("intConstant");
            cur->A.push_back(INT_CONSTANT());
            return cur;
        }
    if (Scanner::nxtLexeme() == "(")
        {
            cur->A.push_back("(");
            assertLexeme("(");
            cur->B.push_back(EXPRESSION());
            assertLexeme(")");
            return cur;
        }
    if (FUNCS.count(Scanner::nxtLexeme()))
        {
            cur->A.push_back("callFunction");
            cur->A.push_back(NAME());
            assertLexeme("(");
            cur->B = OPTARGUS();
            assertLexeme(")");
            return cur;
        }
    cur->A.push_back("callVariable");
    cur->A.push_back(NAME());
    while (Scanner::nxtLexeme() == "[")
        {
            assertLexeme("[");
            cur->B.push_back(EXPRESSION());
            assertLexeme("]");
        }
    return cur;
}
 
Lexitree* UNIT1()
{
    Lexitree* cur = new Lexitree;
    if ((Scanner::nxtLexeme() == "+") || (Scanner::nxtLexeme() == "-") || (Scanner::nxtLexeme() == "!"))
        {
            cur->A.push_back(Scanner::getLexeme());
            cur->B.push_back(UNIT1());
            return cur;
        }
    cur->B.push_back(UNIT0());
    return cur;
}
 
Lexitree* UNIT2()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT1());
    string lex;
    while (((lex = Scanner::nxtLexeme()) == "*") || (lex == "/") || (lex == "%"))
        {
            cur->A.push_back(Scanner::getLexeme());
            cur->B.push_back(UNIT1());
        }
    return cur;
}
 
Lexitree* UNIT3()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT2());
    string lex;
    while (((lex = Scanner::nxtLexeme()) == "+") || (lex == "-"))
        {
            cur->A.push_back(Scanner::getLexeme());
            cur->B.push_back(UNIT2());
        }
    return cur;
}
 
Lexitree* UNIT4()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT3());
    string lex;
    while (((lex = Scanner::nxtLexeme()) == "<") || (lex == ">") || (lex == "<=") || (lex == ">="))
        {
            cur->A.push_back(Scanner::getLexeme());
            cur->B.push_back(UNIT3());
        }
    return cur;
}
 
Lexitree* UNIT5()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT4());
    string lex;
    while (((lex = Scanner::nxtLexeme()) == "==") || (lex == "!="))
        {
            cur->A.push_back(Scanner::getLexeme());
            cur->B.push_back(UNIT4());
        }
    return cur;
}
 
Lexitree* UNIT6()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT5());
    while (Scanner::nxtLexeme() == "^")
        {
            assertLexeme("^");
            cur->B.push_back(UNIT5());
        }
    return cur;
}
 
Lexitree* UNIT7()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT6());
    while (Scanner::nxtLexeme() == "&&")
        {
            assertLexeme("&&");
            cur->B.push_back(UNIT6());
        }
    return cur;
}
 
Lexitree* UNIT8()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT7());
    while (Scanner::nxtLexeme() == "||")
        {
            assertLexeme("||");
            cur->B.push_back(UNIT7());
        }
    return cur;
}
 
Lexitree* UNIT9()
{
    Lexitree* cur = new Lexitree;
    cur->B.push_back(UNIT8());
    while (Scanner::nxtLexeme() == "=")
        {
            assertLexeme("=");
            cur->B.push_back(UNIT8());
        }
    return cur;
}
 
vector<Lexitree*> OPTARGUS()
{
    vector<Lexitree*> ret;
    ret.clear();
    if (Scanner::nxtLexeme() == ")") return ret;
    ret.push_back(EXPRESSION());
    vector<Lexitree*> p = ARGUS();
    ret.insert(ret.end(), p.begin(), p.end());
    return ret;
}
 
vector<Lexitree*> ARGUS()
{
    vector<Lexitree*> ret;
    ret.clear();
    while (Scanner::nxtLexeme() == ",")
        {
            assertLexeme(",");
            ret.push_back(EXPRESSION());
        }
    return ret;
}
 
vector<Lexitree*> DEFINEVARS()
{
    vector<Lexitree*> ret;
    ret.clear();
    while (Scanner::nxtLexeme() == ",")
        {
            assertLexeme(",");
            ret.push_back(DEFINEVAR());
        }
    return ret;
}
 
Lexitree* DEFINEVAR()
{
    Lexitree* cur = new Lexitree;
    cur->A.push_back(NAME());
    while (Scanner::nxtLexeme() == "[")
        {
            assertLexeme("[");
            cur->A.push_back(INT_CONSTANT());
            assertLexeme("]");
        }
    return cur;
}
 
string NAME()
{
    string ret = Scanner::getLexeme();
    if (lexemeType(ret) != TNAME)
        {
            stringstream ss;
            ss.str("");
            ss << "expected a NAME-type lexeme, but lexeme " << ret << "found." << endl;
            throw ss.str();
        }
    return ret;
}
 
string INT_CONSTANT()
{
    string ret = Scanner::getLexeme();
    if (lexemeType(ret) != TINTCONSTANT)
        {
            stringstream ss;
            ss.str("");
            ss << "expected a INT-type lexeme, but lexeme " << ret << "found." << endl;
            throw ss.str();
        }
    return ret;
}
 
// 语法分析器结束
//--------------------------------------------------
// 解释环境（变量环境，内存管理）开始
 
Lexitree* THE_PROGRAM;
int Memo[3<<21];
 
const int TADDRESSED = 0;
const int TFREE = 1;
 
struct Int
{
    int T, X;
    Int() {}
    Int(int c)
    {
        T = TFREE;
        X = c;
    }
    Int(int t, int x)
    {
        T = t;
        X = x;
    }
    int to_i()
    {
        return (T == TFREE) ? X : Memo[X];
    }
    Int operator [](int r)
    {
        return Int(TADDRESSED, to_i() + r);
    }
    string to_str()
    {
        stringstream ss;
        ss.str("");
        if (T == TFREE)
            ss << X;
        else
            ss << Memo[X] << "(&" << X << ")";
        return ss.str();
    }
};
 
namespace memManage
{
    // 内存管理
    vector<int> S;
    void Init()
    {
        S.clear();
        S.push_back(0);
    }
    int Request(vector<int> SZ)
    {
        int ret = S.back(), L, R, i;
        L = ret; R = ret;
        for (vector<int>::iterator it = SZ.begin(); it != SZ.end(); it++)
            {
                int nxtL = R + 1;
                fortodo(i, L, R)
                    {
                        Memo[i] = nxtL;
                        nxtL += *it;
                    }
                L = R + 1;
                R = nxtL - 1;
            }
        fortodo(i, L, R) Memo[i] = 0;
        S.push_back(R + 1);
        return ret;
    }
    void deRequest()
    {
        S.pop_back();
    }
};
 
namespace Env
{
    // 变量环境
    map<string,vector<int> > MSVI;
    vector<vector<string> > VVS;
    vector<multiset<string> > VSS;
    set<string> globalVariables;
    void Init()
    {
        MSVI.clear();
        VVS.clear();
        VSS.clear();
    }
    void newNamespace()
    {
        vector<string> newVec;
        newVec.clear();
        VVS.push_back(newVec);
    }
    void newFunction()
    {
        multiset<string> newSet;
        newSet.clear();
        VSS.push_back(newSet);
    }
    void exitNamespace()
    {
        vector<string> VB = VVS.back();
        VVS.pop_back();
        for (vector<string>::reverse_iterator rit = VB.rbegin(); rit != VB.rend(); rit++)
            {
                memManage::deRequest();
                MSVI[*rit].pop_back();
                VSS.back().erase(VSS.back().find(*rit));
            }
    }
    void exitFunction()
    {
        VSS.pop_back();
    }
    void declare(vector<string> M)
    {
        string Name = M[0];
        int SZ = int(M.size()), i;
        vector<int> arrSZ;
        arrSZ.clear();
        fortodo(i, 1, SZ - 1)
            arrSZ.push_back(to_i(M[i]));
        VVS.back().push_back(Name);
        VSS.back().insert(Name);
        MSVI[Name].push_back(memManage::Request(arrSZ));
    }
    Int callVariable(string a)
    {
        //printf("%s is at &%d\n", a.c_str(), MSVI[a].back());
        if (VSS.back().count(a))
            return Int(TADDRESSED, MSVI[a].back()); // it calls a Local Variable
        else
            return Int(TADDRESSED, MSVI[a].front()); // it calls a Global Variable
    }
};
 
// 解释环境结束
//--------------------------------------------------
// 解释器开始
 
FILE* fin;
map<string,Lexitree*> MSLT;
 
const int ADDCIN = -1;
const int ADDCOUT = -2;
const int ADDENDL = -3;
 
void iSTATEMENTS(Lexitree* cur);
void iSTATEMENT(Lexitree* cur);
void iSTATEMENT_IN_FOR(Lexitree* cur);
Int iOPTEXPRESSION(Lexitree* cur);
Int iEXPRESSION(Lexitree* cur);
Int iUNIT0(Lexitree* cur);
Int iUNIT1(Lexitree* cur);
Int iUNIT2(Lexitree* cur);
Int iUNIT3(Lexitree* cur);
Int iUNIT4(Lexitree* cur);
Int iUNIT5(Lexitree* cur);
Int iUNIT6(Lexitree* cur);
Int iUNIT7(Lexitree* cur);
Int iUNIT8(Lexitree* cur);
Int iUNIT9(Lexitree* cur);
 
bool RETURN;
int RETURN_VALUE;
 
Int callFunction(string functionName, vector<int> parameters)
{
    /*cout << functionName << "(";
    for (vector<int>::iterator it = parameters.begin(); it != parameters.end(); it++)
        cout << " " << *it;
    cout << ")\n";*/
    if (functionName == "putchar") // 内置函数
        {
            if (parameters.size() != 1)
                throw string("wrong number of argument for putchar()");
            return Int(putchar(parameters[0]));
        }
    if (MSLT.count(functionName) == 0)
        {
            stringstream ss;
            ss.str();
            ss << "no such function called " << functionName << ".";
            throw ss.str();
        }
    Lexitree* cur = MSLT[functionName];
    if (parameters.size() != cur->A.size() - 1)
        {
            stringstream ss;
            ss.str();
            ss << "wrong number of argument for " << functionName << "()";
            throw ss.str();
        }
    Env::newFunction();
    Env::newNamespace();
    int i;
    fortodo(i, 0, int(parameters.size()) - 1)
        {
            Env::declare(vector<string>(cur->A.begin() + i + 1, cur->A.begin() + i + 2));
            Int add = Env::callVariable(cur->A[i + 1]);
            Memo[add.X] = parameters[i];
        }
    RETURN = false;
    iSTATEMENTS(cur->B[0]);
    Env::exitNamespace();
    Env::exitFunction();
    if (RETURN)
        {
            RETURN = false;
            return Int(RETURN_VALUE);
        }
    else
        return Int(0);
}
 
void iSTATEMENTS(Lexitree* cur)
{
    for (vector<Lexitree*>::iterator it = cur->B.begin(); it != cur->B.end(); it++)
        iSTATEMENT(*it);
}
 
void iSTATEMENT(Lexitree* cur)
{
    if (RETURN) return;
    if (cur->A[0] == "if")
        {
            Int rez = iEXPRESSION(cur->B[0]);
            if (rez.to_i())
                iSTATEMENT(cur->B[1]);
            else
                if (cur->B.size() == 3)
                    iSTATEMENT(cur->B[2]);
            return;
        }
    if (cur->A[0] == "int")
        {
            for (vector<Lexitree*>::iterator it = cur->B.begin(); it != cur->B.end(); it++)
                Env::declare((*it)->A);
            return;
        }
    if (cur->A[0] == "{")
        {
            Env::newNamespace();
            iSTATEMENTS(cur->B[0]);
            Env::exitNamespace();
            return;
        }
    if (cur->A[0] == "for")
        {
            Env::newNamespace();
            for (iSTATEMENT_IN_FOR(cur->B[0]); iOPTEXPRESSION(cur->B[1]).to_i(); iSTATEMENT_IN_FOR(cur->B[2]))
                {
                    iSTATEMENT(cur->B[3]);
                    if (RETURN) return;
                }
            Env::exitNamespace();
            return;
        }
    if (cur->A[0] == "while")
        {
            while (iEXPRESSION(cur->B[0]).to_i())
                {
                    iSTATEMENT(cur->B[1]);
                    if (RETURN) return;
                }
            return;
        }
    if (cur->A[0] == "return")
        {
            int ret = iEXPRESSION(cur->B[0]).to_i();
            RETURN = true;
            RETURN_VALUE = ret;
            return;
        }
    iEXPRESSION(cur->B[0]);
    return;
}
 
void iSTATEMENT_IN_FOR(Lexitree* cur)
{
    if (cur->A.size() == 0) return;
    if (cur->A[0] == "int")
        {
            for (vector<Lexitree*>::iterator it = cur->B.begin(); it != cur->B.end(); it++)
                Env::declare((*it)->A);
            return;
        }
    iEXPRESSION(cur->B[0]);
    return;
}
 
Int iOPTEXPRESSION(Lexitree* cur)
{
    if (cur->B.size() == 0)
        return Int(1);
    else
        return iEXPRESSION(cur->B[0]);
}
 
Int iEXPRESSION(Lexitree* cur)
{
    vector<Int> lst;
    lst.clear();
    for (vector<Lexitree*>::iterator it = cur->B.begin(); it != cur->B.end(); it++)
        lst.push_back(iUNIT9(*it));
    int ASZ = int(cur->A.size()), i;
    fortodo(i, 0, ASZ - 1)
        if (cur->A[i] == "<<")
            if ((lst[i + 1].T == TADDRESSED) && (lst[i + 1].X == ADDENDL))
                cout << endl;
            else
                cout << lst[i + 1].to_i();
        else
            Memo[lst[i + 1].X] = *(FINpointer++);
    return lst[0];
}
 
Int iUNIT0(Lexitree* cur)
{
    if (cur->A[0] == "cin") return Int(TADDRESSED, ADDCIN);
    if (cur->A[0] == "cout") return Int(TADDRESSED, ADDCOUT);
    if (cur->A[0] == "endl") return Int(TADDRESSED, ADDENDL);
    if (cur->A[0] == "intConstant") return Int(TFREE, to_i(cur->A[1]));
    if (cur->A[0] == "(") return iEXPRESSION(cur->B[0]);
    if (cur->A[0] == "callFunction")
        {
            vector<int> parameters;
            parameters.clear();
            for (vector<Lexitree*>::iterator it = cur->B.begin(); it != cur->B.end(); it++)
                parameters.push_back(iEXPRESSION(*it).to_i());
            return callFunction(cur->A[1], parameters);
        }
    Int ret = Env::callVariable(cur->A[1]);
    for (vector<Lexitree*>::iterator it = cur->B.begin(); it != cur->B.end(); it++)
        ret = ret[iEXPRESSION(*it).to_i()];
    return ret;
}
 
Int iUNIT1(Lexitree* cur)
{
    if (cur->A.size())
        {
            if (cur->A[0] == "+")
                {
                    Int las = iUNIT1(cur->B[0]);
                    return Int(TFREE, las.to_i());
                }
            if (cur->A[0] == "-")
                {
                    Int las = iUNIT1(cur->B[0]);
                    return Int(TFREE, - las.to_i());
                }
            if (cur->A[0] == "!")
                {
                    Int las = iUNIT1(cur->B[0]);
                    return Int(TFREE, (las.to_i() == 0) ? 1 : 0);
                }
        }
    Int ret = iUNIT0(cur->B[0]);
    return ret;
}
 
Int iUNIT2(Lexitree* cur)
{
    Int ret = iUNIT1(cur->B[0]);
    int ASZ = cur->A.size(), i;
    fortodo(i, 0, ASZ - 1)
        {
            Int nxret = iUNIT1(cur->B[i + 1]);
            if (cur->A[i] == "*") ret = Int(TFREE, ret.to_i() * nxret.to_i());
            if (cur->A[i] == "/") ret = Int(TFREE, ret.to_i() / nxret.to_i());
            if (cur->A[i] == "%") ret = Int(TFREE, ret.to_i() % nxret.to_i());
        }
    return ret;
}
 
Int iUNIT3(Lexitree* cur)
{
    Int ret = iUNIT2(cur->B[0]);
    int ASZ = cur->A.size(), i;
    fortodo(i, 0, ASZ - 1)
        {
            Int nxret = iUNIT2(cur->B[i + 1]);
            if (cur->A[i] == "+") ret = Int(TFREE, ret.to_i() + nxret.to_i());
            if (cur->A[i] == "-") ret = Int(TFREE, ret.to_i() - nxret.to_i());
        }
    return ret;
}
 
Int iUNIT4(Lexitree* cur)
{
    Int ret = iUNIT3(cur->B[0]);
    int ASZ = cur->A.size(), i;
    fortodo(i, 0, ASZ - 1)
        {
            Int nxret = iUNIT3(cur->B[i + 1]);
            if (cur->A[i] == "<") ret = Int(TFREE, (ret.to_i() < nxret.to_i()) ? 1 : 0);
            if (cur->A[i] == ">") ret = Int(TFREE, (ret.to_i() > nxret.to_i()) ? 1 : 0);
            if (cur->A[i] == "<=") ret = Int(TFREE, (ret.to_i() <= nxret.to_i()) ? 1 : 0);
            if (cur->A[i] == ">=") ret = Int(TFREE, (ret.to_i() >= nxret.to_i()) ? 1 : 0);
        }
    return ret;
}
 
Int iUNIT5(Lexitree* cur)
{
    Int ret = iUNIT4(cur->B[0]);
    int ASZ = cur->A.size(), i;
    fortodo(i, 0, ASZ - 1)
        {
            Int nxret = iUNIT4(cur->B[i + 1]);
            if (cur->A[i] == "==") ret = Int(TFREE, (ret.to_i() == nxret.to_i()) ? 1 : 0);
            if (cur->A[i] == "!=") ret = Int(TFREE, (ret.to_i() != nxret.to_i()) ? 1 : 0);
        }
    return ret;
}
 
Int iUNIT6(Lexitree* cur)
{
    Int ret = iUNIT5(cur->B[0]);
    int ASZ = cur->B.size() - 1, i;
    fortodo(i, 0, ASZ - 1)
        {
            Int nxret = iUNIT5(cur->B[i + 1]);
            ret = Int(TFREE, ((ret.to_i() == 0) ^ (nxret.to_i() == 0)) ? 1 : 0);
        }
    return ret;
}
 
Int iUNIT7(Lexitree* cur)
{
    Int ret = iUNIT6(cur->B[0]);
    int ASZ = cur->B.size() - 1, i;
    fortodo(i, 0, ASZ - 1)
        {
            Int nxret = iUNIT6(cur->B[i + 1]);
            ret = Int(TFREE, ((ret.to_i() == 0) || (nxret.to_i() == 0)) ? 0 : 1);
        }
    return ret;
}
 
Int iUNIT8(Lexitree* cur)
{
    Int ret = iUNIT7(cur->B[0]);
    int ASZ = cur->B.size() - 1, i;
    fortodo(i, 0, ASZ - 1)
        {
            Int nxret = iUNIT7(cur->B[i + 1]);
            ret = Int(TFREE, ((ret.to_i() == 0) && (nxret.to_i() == 0)) ? 0 : 1);
        }
    return ret;
}
 
Int iUNIT9(Lexitree* cur)
{
    int BSZ = cur->B.size();
    if (BSZ == 1)
        return iUNIT8(cur->B[0]);
    vector<Int> VS;
    VS.clear();
    for (vector<Lexitree*>::iterator it = cur->B.begin(); it != cur->B.end(); it++)
        VS.push_back(iUNIT8(*it));
    int laz = VS.back().to_i();
    int i;
    fortodo(i, 0, BSZ - 2)
        Memo[VS[i].X] = laz;
    return VS.front();
}
 
// 解释器结束
//--------------------------------------------------
 
int main()
{
    int countInputNumbers;
    scanf("%d", &countInputNumbers);
    FIN.clear();
    for (; countInputNumbers; countInputNumbers--)
        {
            int u;
            scanf("%d", &u);
            FIN.push_back(u);
        }
    FINpointer = FIN.begin();
    Cursor::Init();
    Scanner::Init();
    memManage::Init();
    Env::Init();
    FUNCS.clear();
    FUNCS.insert("putchar");
    try
    {
        THE_PROGRAM = PROGRAM();
    }
    catch (string MESSAGE)
    {
        printf("Compile Failed.\n");
        cout << MESSAGE << endl;
        return 0;
    }
    Env::newFunction();
    MSLT.clear();
    int N = THE_PROGRAM->A.size(), i;
    Env::newNamespace();
    fortodo(i, 0, N - 1)
        if (THE_PROGRAM->A[i] == "Function")
            MSLT[THE_PROGRAM->B[i]->A[0]] = THE_PROGRAM->B[i];
        else
            for (vector<Lexitree*>::iterator it = THE_PROGRAM->B[i]->B.begin(); it != THE_PROGRAM->B[i]->B.end(); it++)
                Env::declare((*it)->A);
    try
    {
        vector<int> emp;
        emp.clear();
        callFunction("main", emp);
    }
    catch (string MESSAGE)
    {
        printf("Interpret Failed.\n");
        cout << MESSAGE << endl;
        return 0;
    }
    return 0;
}
