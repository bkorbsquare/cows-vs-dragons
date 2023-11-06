// Function to capture a single keystroke in non-blocking mode
int getKeystroke() {
    struct termios oldTerm, newTerm;
    tcgetattr(STDIN_FILENO, &oldTerm);
    newTerm = oldTerm;
    newTerm.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTerm);

    int key = EOF;
    fd_set set;
    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);

    if (select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout) > 0) {
        key = getchar();
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldTerm);
    return key;
}

int main() {
    int keyCount = 0;
    int requiredKeystrokes = 30;
    int choice;
    int gameActive = 1;

    while(gameActive) {
        // Titlescreen
        printf("Wecome to-->\n");

        printf("                                                                                                                                     \n");
        printf("        ░█████╗░░█████╗░░██╗░░░░░░░██╗░██████╗░░░░░░██╗░░░██╗░██████╗░░░░░░██████╗░██████╗░░█████╗░░██████╗░░█████╗░███╗░░██╗░██████╗\n");
        printf("        ██╔══██╗██╔══██╗░██║░░██╗░░██║██╔════╝░░░░░░██║░░░██║██╔════╝░░░░░░██╔══██╗██╔══██╗██╔══██╗██╔════╝░██╔══██╗████╗░██║██╔════╝\n");
        printf("        ██║░░╚═╝██║░░██║░╚██╗████╗██╔╝╚█████╗░█████╗╚██╗░██╔╝╚█████╗░█████╗██║░░██║██████╔╝███████║██║░░██╗░██║░░██║██╔██╗██║╚█████╗░\n");
        printf("        ██║░░██╗██║░░██║░░████╔═████║░░╚═══██╗╚════╝░╚████╔╝░░╚═══██╗╚════╝██║░░██║██╔══██╗██╔══██║██║░░╚██╗██║░░██║██║╚████║░╚═══██╗\n");
        printf("        ╚█████╔╝╚█████╔╝░░╚██╔╝░╚██╔╝░██████╔╝░░░░░░░░╚██╔╝░░██████╔╝░░░░░░██████╔╝██║░░██║██║░░██║╚██████╔╝╚█████╔╝██║░╚███║██████╔╝\n");
        printf("        ░╚════╝░░╚════╝░░░░╚═╝░░░╚═╝░░╚═════╝░░░░░░░░░░╚═╝░░░╚═════╝░░░░░░░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░╚═════╝░░╚════╝░╚═╝░░╚══╝╚═════╝░\n");

        printf("[Press Enter to start]\n");
        getchar();

        // Storyline
        printf("This is our Hero, Bessy -->\n");

        printf(" _____                      \n");
        printf("< Moo >                     \n");
        printf(" -----                      \n");
        printf("    \\   ^__^               \n");
        printf("     \\  (oo)\\_______      \n");
        printf("        (__)\\        )\\/\\\n");
        printf("             ||----w |      \n");
        printf("             ||     ||      \n");

        printf("[Press Enter to continue]\n");
        getchar();

        printf("And her nemesis, the Dragon -->\n");

        printf("                          ______ \n");
        printf("                         < Rawr >\n");
        printf("                \\||/      ------\n");
        printf("                |  @___oo   /    \n");
        printf("      /\\  /\\   / (__,,,,|  /   \n");
        printf("     ) /^\\)^\\ / _)             \n");
        printf("     )   /^\\/   _)              \n");
        printf("     )   _ /  / _)               \n");
        printf(" /\\  )/\\/ ||  | )_)            \n");
        printf("<  >      |(,,) )__)             \n");
        printf(" ||       /   \\)___)\\          \n");
        printf(" | \\____(      )___) )___       \n");
        printf("  \\______(_______;;; __;;;      \n");

        printf("[Press Enter to continue]\n");
        getchar();

        printf("The Dragon has attacked poor Bessy's farm, and burnt the farmer to a crisp.\n");
        printf("[Press Enter to continue]\n");
        getchar();

        printf("Bessy's friends Daisy & Blackjack have high-tailed it into the back pasture, and now Bessy stands alone in the yard as the mighty lizard circles to make another pass.\n");
        printf("[Press Enter to continue]\n");
        getchar();

        while (1) {
            printf("What should Bessy do?\n");
            printf("1. Follow her friends and run away!\n");
            printf("2. Make a stand and look to fight!\n");

            printf("Enter your choice (1 or 2):");
            scanf("%d", &choice);
            getchar();

            if (choice == 1) {
                printf("\n");
                printf("Bessy decides to follow her friends and run away!\n");
                printf("Bessy gets ROASTED. She doesn't make it out of the yard by the time the dragon lights her up, quickly followed by the nearby fields, and her friends. Your cowardice has devastated the farm.\n");
                printf("[Press Enter to continue]\n");
                getchar();
                printf(". . .\n");
                printf(". . .\n");
                printf(". . .\n");
                printf("                                                                           \n");
                printf("    ░██████╗░░█████╗░███╗░░░███╗███████╗  ░█████╗░██╗░░░██╗███████╗██████╗░\n");
                printf("    ██╔════╝░██╔══██╗████╗░████║██╔════╝  ██╔══██╗██║░░░██║██╔════╝██╔══██╗\n");
                printf("    ██║░░██╗░███████║██╔████╔██║█████╗░░  ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝\n");
                printf("    ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░  ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗\n");
                printf("    ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗  ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║\n");
                printf("    ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝  ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n");
                printf(". . .\n");
                printf(". . .\n");
                printf(". . .\n");
                printf("\n");
                // Wait for 5 seconds
                sleep(5);
                printf("Do you want to play again? (1 for yes, 0 for no):\n");
                printf("\n");
                scanf("%d", &gameActive);
                if (gameActive != 1) {
                    //Exit the loop if the player doesn't want to play again
                    break;
                }
            } else if (choice == 2) {
                printf("\n");
                printf("Bessy chooses to make a stand!\n");
                printf("A battle is about to begin! Lets take a look at the Combat System.\n");
                printf("[Press Enter to continue]\n");
                getchar();
                printf("The Dragon has the following stats-->\n");
                //Dragon stats
                printf("ATTACK: 100\n");
                printf("SPEED: 7/10\n");
                printf("HEALTH: 25\n");
                printf("'Attack' is how much damage is dealt, 'Health' is how much damage can be taken, and 'Speed' determines who swings first.\n");
                printf("[Press Enter to continue]\n");
                getchar();
                printf("Bessy has the following stats-->\n");
                //Bessy stats
                printf("ATTACK: 5\n");
                printf("SPEED: 1/10\n");
                printf("HEALTH: 5\n");
                printf("[Press Enter to continue]\n");
                getchar();
                printf("As you can see, the Dragon has quite an advantage at the moment.\n");
                printf("'Items' and 'Buff' can effect stats. Characters can hold one item at a time, and Buff is the 'X' factor that you can help give our hero in battle!\n");
                printf("[Press Enter to continue]\n");
                getchar();
                printf("Let's give Bessy a Fire Hose (Item) to boost her numbers! The Fire Hose (Item) has the following stats-->\n");
                //Fire Hose stats
                printf("ATTACK: +15\n");
                printf("SPEED: +7\n");
                printf("[Press Enter to continue]\n");
                getchar();
                printf("The Dragon approaches!\n");
                printf("Bessy stands strong holding her Fire Hose (Item) as the ancient beast descends upon her.\n");
                printf("This is our chance to Buff Bessy's attack before the fight!\n");
                printf("[Press Enter to continue]\n");
                getchar();
                printf("Buff Bessy up! Press the space bar as many times as you can within 5 seconds...[Press Enter to start the countdown!]\n");
                getchar();

                // Countdown and print 
                for (int countdown = 5; countdown >= 1; countdown--) {
                    printf("%d  ", countdown);
                    fflush(stdout);

                    time_t startTime = time(NULL);
                    while (difftime(time(NULL), startTime) < 1) {
                        int key = getKeystroke();
                        if (key == ' ') {
                            keyCount++;
                        }
                    }

                    // Print a newline character to separate countdown messages.
                    printf("\n");
                }

                printf("\n");
                printf("Total key count: %d\n", keyCount);

                    if (keyCount >= requiredKeystrokes) {
                        printf("Nice work! You buffed the attack! (Attack +5)\n");
                        printf("[Press Enter to continue]\n");
                        getchar();
                        printf("Bessy's attack was enough to K.O. the Dragon!\n");
                        printf("You saved the farm!\n");
                        printf("[Press Enter to continue]\n");
                        getchar();
                        printf(". . .\n");
                        printf(". . .\n");
                        printf(". . .\n");
                        printf("                                                                 \n");
                        printf("  ██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗██╗██╗██╗\n");
                        printf("  ╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║██║██║██║\n");
                        printf("  ░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║██║██║██║\n");
                        printf("  ░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║╚═╝╚═╝╚═╝\n");
                        printf("  ░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║██╗██╗██╗\n");
                        printf("  ░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝╚═╝╚═╝╚═╝\n");
                        printf(". . .\n");
                        printf(". . .\n");
                        printf(". . .\n");
                        printf("\n");
                        // Wait for 5 seconds
                        sleep(5);
                        printf("Do you want to play again? (1 for yes, 0 for no):\n");
                        printf("\n");
                        scanf("%d", &gameActive);
                        if (gameActive != 1) {
                            //Exit the loop if the player doesn't want to play again
                            break;
                        }
                    } else {
                        printf("No Buff for you.\n");
                        printf("[Press Enter to continue]\n");
                        getchar();
                        printf("Bessy's attack was NOT enough to K.O. the Dragon!\n");
                        printf("The Dragon's attack WAS enough to K.O. Bessy!\n");
                        printf("[Press Enter to continue]\n");
                        getchar();
                        printf(". . .\n");
                        printf(". . .\n");
                        printf(". . .\n");
                        printf("                                                                           \n");
                        printf("    ░██████╗░░█████╗░███╗░░░███╗███████╗  ░█████╗░██╗░░░██╗███████╗██████╗░\n");
                        printf("    ██╔════╝░██╔══██╗████╗░████║██╔════╝  ██╔══██╗██║░░░██║██╔════╝██╔══██╗\n");
                        printf("    ██║░░██╗░███████║██╔████╔██║█████╗░░  ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝\n");
                        printf("    ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░  ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗\n");
                        printf("    ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗  ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║\n");
                        printf("    ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝  ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n");
                        printf(". . .\n");
                        printf(". . .\n");
                        printf(". . .\n");
                        printf("\n");
                        // Wait for 5 seconds
                        sleep(5);
                        printf("Do you want to play again? (1 for yes, 0 for no): ");
                        printf("\n");
                        scanf("%d", &gameActive);
                        if (gameActive != 1) {
                            //Exit the loop if the player doesn't want to play again
                            break;
                        }
                    }

            } else {
                printf("Invalid choice. Please enter 1 or 2.\n");
            }
        }
    }

    return 0;

}
