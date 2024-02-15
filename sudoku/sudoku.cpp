#include <iostream>
#include <string>
#include "generator.h"
#include "pictures.h"
#include "string_extension.h"
#include <fstream>
#include <Windows.h>

#define DEBAG true

using namespace std;

enum Color
{
    White = 15,
    Green = 10,
    Red = 4,
    Black = 0,
    Gray = 8,
    Yello = 6
};

void SetColor(int text, int Fon)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (Fon << 4) + text);
}

class Board
{
    private:
        const string letters = "ABCDEFGHI";
        int lives;
        int matrix[9][9] = { -1 };
        struct blocks_struct
        {
            int block[3][3] = { 0 };
            bool isEdit = true;
            int text_color = White;
            int font_color = Black;
        };
        static const int amount_blocks = 81;
        blocks_struct blocks[amount_blocks];
        void print_block(blocks_struct block, int rows)
        {
            SetColor(block.text_color, block.font_color);
            for (int i = 0; i < 3; i++)
            {
                if (block.block[rows][i] == 0)
                {
                    cout << "  ";
                }
                else
                {
                    cout << block.block[rows][i] << " ";
                }
            }
            SetColor(White, Black);
        }
    public:
        Board(int live)
        {
            lives = live;
            int number_block = 0;
            generator_soduku(matrix);
        #if DEBAG
            string path = "answer.txt";
            ofstream file;
            file.open(path);
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    file << matrix[i][j] << " ";
                }
                file << "\n";
            }
            file.close();
        #endif 
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++, number_block++)
                {
                    if (rand() % 2 == 0)
                    {
                        blocks[number_block].block[1][1] = matrix[i][j];
                        blocks[number_block].isEdit = false;
                    }
                }
            }
        };
        ostream& operator << (std::ostream& os)
        {
            int Number_block = 0;
            int digit = 1;
            int x = 37, y = 37, m = -1;
            int step = 4;
            int amount_space = 6;
            int i = 0;
            for (char ch : letters)
            {
                if (i % 3 == 0 && i != 0)
                {
                    amount_space += 1;
                    cout << multypli_word(amount_space, " ") << ch;
                    amount_space -= 1;
                }
                else
                {
                    cout << multypli_word(amount_space, " ") << ch;
                }
                i++;
            }
            cout << endl;
            for (int i = 0; i < x; i++)
            {
                if (i % step == 0)
                {
                    m += 1;
                }
                Number_block = 9 * m;
                for (int j = 0; j < y; j++)
                {
                    if (j == 0 && (i % 2 == 0 && i != 0) && i % step != 0)
                    {
                        cout << digit << " ";
                        digit++;
                    }
                    else if (j == 0)
                    {
                        cout << "  ";
                    }
                    if ((i % step == 0) && (j % step == 0))
                    {
                        if (j % 12 == 0)
                        {
                            cout << "++";
                        }
                        else
                        {
                            cout << "+";
                        }

                    }
                    else if ((i == 0 || i == x) || i % step == 0)
                    {
                        if (i % 12 == 0)
                        {
                            cout << "==";
                        }
                        else
                        {
                            cout << "--";
                        }
                    }
                    else if (((j == y) || j % step == 0) && ((i != 0 && i != x) && i % step != 0))
                    {
                        if (j % 12 == 0)
                        {
                            cout << "||";
                        }
                        else
                        {
                            cout << "|";
                        }
                    }
                    else
                    {
                        print_block(blocks[Number_block], (i % step) - 1);
                        Number_block++;
                        j += 2;
                    }
                }
                cout << endl;
            }

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < lives; j++)
                {
                    cout << hearts[i] << "\t ";
                }
                cout << endl;
            }
        }
};

class game
{

};

int main()
{
    std::cout << "Hello World!\n";
}
