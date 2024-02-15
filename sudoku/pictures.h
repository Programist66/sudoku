#pragma once
#include <iostream>

const std::string hearts[10] = { "   _..._     _..._  ",
                                 " .$$$$$$$sss$$$$$$$.",
                                 " $$$$$$$$$$$$$$$$$$$",
                                 " $$$$$$$$$$$$$$$$$$$",
                                 " '$$$$$$$$$$$$$$$$$'",
                                 "  '$$$$$$$$$$$$$$$' ",
                                 "   '$$$$$$$$$$$$$'  ",
                                 "     '$$$$$$$$$'    ",
                                 "       '$$$$$'      ",
                                 "         '$'        " };

const std::string lose[16] = {"YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU      LLLLLLLLLLL                   OOOOOOOOO         SSSSSSSSSSSSSSS  EEEEEEEEEEEEEEEEEEEEEE\n"
                              "Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U      L:::::::::L                 OO:::::::::OO     SS:::::::::::::::S E::::::::::::::::::::E\n"
                              "Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U      L:::::::::L               OO:::::::::::::OO  S:::::SSSSSS::::::S E::::::::::::::::::::E\n"
                              "Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU      LL:::::::LL              O:::::::OOO:::::::O S:::::S     SSSSSSS EE::::::EEEEEEEEE::::E\n"
                              "YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U         L:::::L                O::::::O   O::::::O S:::::S               E:::::E       EEEEEE\n"
                              "   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U         L:::::L                O:::::O     O:::::O S:::::S               E:::::E             \n"
                              "    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         L:::::L                O:::::O     O:::::O  S::::SSSS            E::::::EEEEEEEEEE   \n"
                              "     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U         L:::::L                O:::::O     O:::::O   SS::::::SSSSS       E:::::::::::::::E   \n"
                              "      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U         L:::::L                O:::::O     O:::::O     SSS::::::::SS     E:::::::::::::::E   \n"
                              "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U         L:::::L                O:::::O     O:::::O        SSSSSS::::S    E::::::EEEEEEEEEE   \n"
                              "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U         L:::::L                O:::::O     O:::::O             S:::::S   E:::::E             \n"
                              "       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U         L:::::L         LLLLLL O::::::O   O::::::O             S:::::S   E:::::E       EEEEEE\n"
                              "       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U       LL:::::::LLLLLLLLL:::::L O:::::::OOO:::::::O SSSSSSS     S:::::S EE::::::EEEEEEEE:::::E\n"
                              "    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU        L::::::::::::::::::::::L  OO:::::::::::::OO  S::::::SSSSSS:::::S E::::::::::::::::::::E\n"
                              "    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU          L::::::::::::::::::::::L    OO:::::::::OO    S:::::::::::::::SS  E::::::::::::::::::::E\n"
                              "    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU            LLLLLLLLLLLLLLLLLLLLLLLL      OOOOOOOOO       SSSSSSSSSSSSSSS    EEEEEEEEEEEEEEEEEEEEEE\n" };

const std::string win[16] = { "YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU      WWWWWWWW                           WWWWWWWW IIIIIIIIII NNNNNNNN        NNNNNNNN\n"
                              "Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U      W::::::W                           W::::::W I::::::::I N:::::::N       N::::::N\n"
                              "Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U      W::::::W                           W::::::W I::::::::I N::::::::N      N::::::N\n"
                              "Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU      W::::::W                           W::::::W II::::::II N:::::::::N     N::::::N\n"
                              "YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U        W:::::W           WWWWW           W:::::W    I::::I   N::::::::::N    N::::::N\n"
                              "   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U         W:::::W         W:::::W         W:::::W     I::::I   N:::::::::::N   N::::::N\n"
                              "    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U          W:::::W       W:::::::W       W:::::W      I::::I   N:::::::N::::N  N::::::N\n"
                              "     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U           W:::::W     W:::::::::W     W:::::W       I::::I   N::::::N N::::N N::::::N\n"
                              "      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U            W:::::W   W:::::W:::::W   W:::::W        I::::I   N::::::N  N::::N:::::::N\n"
                              "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W W:::::W W:::::W W:::::W         I::::I   N::::::N   N:::::::::::N\n"
                              "       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U              W:::::W:::::W   W:::::W:::::W          I::::I   N::::::N    N::::::::::N\n"
                              "       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U               W:::::::::W     W:::::::::W           I::::I   N::::::N     N:::::::::N\n"
                              "       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U                W:::::::W       W:::::::W          II::::::II N::::::N      N::::::::N\n"
                              "    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                  W:::::W         W:::::W           I::::::::I N::::::N       N:::::::N\n"
                              "    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                     W:::W           W:::W            I::::::::I N::::::N        N::::::N\n"
                              "    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                        WWW             WWW             IIIIIIIIII NNNNNNNN         NNNNNNN\n" };