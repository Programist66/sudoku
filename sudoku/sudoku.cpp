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
        int addres_to_number_block(string addres)
        {
            int number_block = 0;
            int digit = 0;
            if (is_Letter(addres[0]) && is_Digit(addres[1]))
            {
                digit = addres[1] - '0';
                number_block = (digit - 1) * 9 + letter_to_digit(addres[0]);
            }
            else if (is_Letter(addres[1]) && is_Digit(addres[0]))
            {
                digit = addres[0] - '0';
                number_block = (digit - 1) * 9 + letter_to_digit(addres[1]);
            }
            return number_block;
        }
        int find_centre(string addres)
        {
            int x = 0, y = 0;
            if (is_Letter(addres[0]))
            {
                x = letter_to_digit(addres[0]);
                y = addres[1] - '0';
                y -= 1;
            }
            if (is_Letter(addres[1]))
            {
                x = letter_to_digit(addres[1]);
                y = addres[0] - '0';
                y -= 1;
            }
            x--;
            y--;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (x + i >= 0 && y + j >= 0)
                    {
                        if ((x + i) % 3 == 0 && (y + j) % 3 == 0)
                        {
                            x += i; x++;
                            y += j; y++;
                        }
                    }
                }
            }
            return y * 9 + x;
        }
        bool check_colomn(string addres)
        {
            bool have_error = false;
            blocks_struct* p_block = &blocks[addres_to_number_block(addres)];
            int digit = p_block->block[1][1];
            if (is_Letter(addres[0]))
            {
                int colomn = letter_to_digit(addres[0]);
                for (int i = 0; i < 9; i++)
                {
                    int block_number = colomn + 9 * i;
                    if (blocks[block_number].block[1][1] == digit && (block_number != addres_to_number_block(addres)) && blocks[block_number].block[1][1] != 0)
                    {
                        p_block->font_color = Red;
                        blocks[block_number].font_color = Red;
                        have_error = true;
                    }
                    else if (block_number != addres_to_number_block(addres))
                    {
                        blocks[block_number].font_color = Black;
                    }
                }
            }
            return have_error;
        }
        bool check_row(string addres)
        {
            bool have_error = false;
            blocks_struct* p_block = &blocks[addres_to_number_block(addres)];
            int digit = p_block->block[1][1];
            if (is_Letter(addres[0]))
            {
                int row = addres[1] - '0';
                row--;
                for (int i = 0; i < 9; i++)
                {
                    int block_number = row * 9 + i;
                    if (blocks[block_number].block[1][1] == digit && (block_number !=
                        addres_to_number_block(addres)) && blocks[block_number].block[1][1] != 0)
                    {
                        p_block->font_color = Red;
                        blocks[block_number].font_color = Red;
                        have_error = true;
                    }
                    else if (block_number != addres_to_number_block(addres))
                    {
                        blocks[block_number].font_color = Black;
                    }
                }
            }
            if (is_Letter(addres[1]))
            {
                int row = addres[0] - '0';
                for (int i = 0; i < 9; i++)
                {
                    int block_number = row * 9 + i;
                    if (blocks[block_number].block[1][1] == digit && (block_number !=
                        addres_to_number_block(addres)) && blocks[block_number].block[1][1] != 0)
                    {
                        p_block->font_color = Red;
                        blocks[block_number].font_color = Red;
                        have_error = true;
                    }
                    else if (block_number != addres_to_number_block(addres))
                    {
                        blocks[block_number].font_color = Black;
                    }
                }
            }
            return have_error;
        }
        bool check_square(string addres)
        {
            bool have_error = false;
            int number_centre_block = find_centre(addres);
            blocks_struct* p_block = &blocks[addres_to_number_block(addres)];
            int digit = p_block->block[1][1];
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int block_number = number_centre_block + (i * 9) + j;
                    if (blocks[block_number].block[1][1] == digit && (block_number !=
                        addres_to_number_block(addres)) && blocks[block_number].block[1][1] != 0)
                    {
                        have_error = true;
                        p_block->font_color = Red;
                        blocks[block_number].font_color = Red;
                    }
                    else if (block_number != addres_to_number_block(addres))
                    {
                        blocks[block_number].font_color = Black;
                    }
                }
            }
            return have_error;
        }

    public:
        Board(int live)
        {
            lives = live;
            int number_block = 0;
            generator_soduku(matrix);
        #if DEBAG
            string path = "E:/Zolotuhin/sudoku/sudoku/answer.txt";
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
        void PrintBoard()
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

            for (int i = 0; i < size_heart_pictures; i++)
            {
                for (int j = 0; j < lives; j++)
                {
                    cout << hearts[i] << "\t ";
                }
                cout << endl;
            }
        }

        bool all_completed()
        {
            int number_block = 0;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++, number_block++)
                {
                    if (matrix[i][j] != blocks[number_block].block[1][1])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        void set_digit(string addres)
        {
            int digit = 0;
            blocks_struct* p_block = &blocks[addres_to_number_block(addres)];
            p_block->font_color = Gray;
            system("cls");
            PrintBoard();
            if (!(p_block->isEdit))
            {
                p_block->font_color = Black;
                cout << "Вы не можете изменить эту ячейку!!" << endl;
            }
            else
            {
                do
                {
                    cout << "Введите число которое хотите поставить или поменять предыдущее([-1] - выбрать другую ячейку, [0] - стереть значение) : ";
                    cin >> digit;
                    if (digit < -1 || digit > 9)
                    {
                        cout << "Поставте число от -1 до 9!!!" << endl;
                    }
                } while (digit < 0 || digit > 9);
                if (digit == -1)
                {
                    p_block->font_color = Black;
                    system("cls");
                }
                else
                {
                    p_block->block[1][1] = digit;
                    p_block->font_color = Black;
                    p_block->text_color = Yello;
                }
            }
        }

        void reset_blocks()
        {
            for (int i = 0; i < 81; i++)
            {
                if (blocks[i].font_color != Red && blocks[i].font_color != Green)
                {
                    blocks[i].font_color = Black;
                }
            }
        }

        bool check_on_error(string addres)
        {
            check_colomn(addres);
            check_row(addres);
            check_square(addres);
            return check_row(addres) || check_colomn(addres) || check_square(addres);
        }

        void complete_row()
        {
            int number_block = 0;
            for (int i = 0; i < 9; i++)
            {
                bool is_error = false;
                for (int j = 0; j < 9; j++, number_block++)
                {
                    if (matrix[i][j] != blocks[number_block].block[1][1])
                    {
                        is_error = true;
                    }
                }
                if (!is_error)
                {
                    number_block -= 9;
                    for (int j = 0; j < 9; j++, number_block++)
                    {
                        blocks[number_block].font_color = Green;
                    }
                }
            }
        }

        void complete_col()
        {
            int number_block = 0;
            for (int i = 0; i < 9; i++)
            {
                bool is_error = false;
                number_block = i;
                for (int j = 0; j < 9; j++, number_block += 9)
                {
                    if (matrix[j][i] != blocks[number_block].block[1][1])
                    {
                        is_error = true;
                    }
                }
                if (!is_error)
                {
                    number_block -= 81;
                    for (int j = 0; j < 9; j++, number_block += 9)
                    {
                        blocks[number_block].font_color = Green;
                    }
                }
            }
        }

        void complete_square()
        {
            int number_block = 0;
            int save;
            for (int i = -1; i < 8; i++)
            {
                for (int j = -1; j < 8; j++, number_block++)
                {
                    if (i % 3 == 0 && j % 3 == 0)
                    {
                        save = number_block;
                        bool is_error = false;
                        for (int x = -1; x < 2; x++)
                        {
                            for (int y = -1; y < 2; y++)
                            {
                                number_block = save + (x * 9) + y;
                                if (matrix[i + 1 + x][j + 1 + y] != blocks[number_block].block[1][1])
                                {
                                    is_error = true;
                                }
                            }
                        }
                        number_block = save;
                        if (!is_error)
                        {
                            for (int x = -1; x < 2; x++)
                            {
                                for (int y = -1; y < 2; y++)
                                {
                                    number_block = save + (x * 9) + y;
                                    blocks[number_block].font_color = Green;
                                }
                            }
                        }
                        number_block = save;
                    }
                }
            }
        }

        void SetLives(int live) 
        {
            lives = live;
        }
};

class Game
{
    private:
        int lives;
        bool is_Correct_addres(string addres)
        {
            return (is_Letter(addres[0]) && is_Digit(addres[1])) || (is_Letter(addres[1]) && is_Digit(addres[0]));  
        }
        string Normalize_Addres(string adres)
        {
            string addres = adres;
            if (is_Letter(addres[0]))
            {
                addres[0] = toupper(addres[0]);
            }
            else
            {
                addres[1] = toupper(addres[1]);
                swap(addres[0], addres[1]);
            }
            return addres;
        }

    public:
        Game()
        {
            int choise;
            do
            {
                system("cls");
                cout << "[1] - легкий уровень(3 ошибки максимум)\n"
                        "[2] - средний уровень(2 ошибки максиум)\n"
                        "[3] - сложный уровень (1 ошибка максиум)\n"
                        "Ваш выбор: ";
                cin >> choise;
            } while (choise < 1 || choise > 3);
            lives = 4 - choise;
        }
        string start()
        {
            Board board(lives);
            system("cls");
            system("title SUDOKU");
            board.PrintBoard();
            while (lives > 0 && !board.all_completed())
            {
                system("cls");
                board.PrintBoard();
                string addres;
                bool is_error;
                do
                {
                    is_error = false;
                    cout << "Введите адрес ячейки(в формате 'А9' или '9A'): ";                    
                    cin >> addres;
                    addres = To_Upper(addres);
                    if (!is_Correct_addres(addres))
                    {
                        cout << "Неверный адрес ячейки!!" << endl;
                        is_error = true;
                    }
                    else
                    {
                        addres = Normalize_Addres(addres);
                    }
                } while (is_error);
                board.set_digit(addres);
                board.reset_blocks();
                if (board.check_on_error(addres))
                {
                    --lives;
                    board.SetLives(lives);
                }
                board.complete_col();
                board.complete_row();
                board.complete_square();
            }
            system("cls");
            if (lives > 0)
            {
                SetColor(Yello, Black);
                return win;
            }
            else
            {
                SetColor(Red, Black);
                return lose;
            }
        }
};

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    Game game; 
    cout << game.start();
    SetColor(White, Black);
}
