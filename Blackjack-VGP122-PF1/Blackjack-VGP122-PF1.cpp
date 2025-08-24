#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

// ---------------- Card + Deck ----------------
struct Card {
    std::string rank;
    std::string suit;
    int value;
};

class Deck {
public:
    Deck() { reset(); }

    void reset() {
        cards.clear();
        std::string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        std::string ranks[] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };

        for (auto& s : suits) {
            for (auto& r : ranks) {
                Card c;
                c.rank = r;
                c.suit = s;
                if (r == "J" || r == "Q" || r == "K") c.value = 10;
                else if (r == "A") c.value = 11;
                else c.value = std::stoi(r);
                cards.push_back(c);
            }
        }
        std::srand((unsigned)time(0));
        std::random_shuffle(cards.begin(), cards.end());
        std::cout << "[DEBUG] Deck created and shuffled (" << cards.size() << " cards)\n";
    }

    Card draw() {
        Card c = cards.back();
        cards.pop_back();
		// [DEBUG] Uncomment the next line to see drawn cards in debug mode
        /* std::cout << "[DEBUG] Drew card: " << c.rank << " of " << c.suit
            << " (value " << c.value << ")\n"; */
        return c;
    }

private:
    std::vector<Card> cards;
};

// ---------------- Utility ----------------
int handValue(std::vector<Card>& hand, bool debug = false) {
    int total = 0;
    int aces = 0;
    for (auto& c : hand) {
        total += c.value;
        if (c.rank == "A") aces++;
    }
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }
    if (debug) {
        std::cout << "[DEBUG] Hand recalculated total = " << total << "\n";
    }
    return total;
}

void printHand(const std::vector<Card>& hand, bool hideFirst = false) {
    for (size_t i = 0; i < hand.size(); i++) {
        if (i == 0 && hideFirst) {
            std::cout << "[Hidden Card], ";
        }
        else {
            std::cout << hand[i].rank << " of " << hand[i].suit << ", ";
        }
    }
    std::cout << std::endl;
}

// ---------------- Banners ----------------
void printBanner() {
    std::cout << ">>=================================================================<<\n";
    std::cout << "||   ____   _         _     ____  _  __    _    _     ____  _  __  ||\n";
    std::cout << "||  | __ ) | |       / \\   / ___|| |/ /   | |  / \\   / ___|| |/ /  ||\n";
    std::cout << "||  |  _ \\ | |      / _ \\ | |    | ' / _  | | / _ \\ | |    | ' /   ||\n";
    std::cout << "||  | |_) || |___  / ___ \\| |___ | . \\| |_| |/ ___ \\| |___ | . \\   ||\n";
    std::cout << "||  |____/ |_____|/_/   \\_\\\\____||_|\\_\\\\___//_/   \\_\\\\____||_|\\_\\  ||\n";
    std::cout << ">>=================================================================<<\n";
    std::cout << "               W E L C O M E   T O   B L A C K J A C K\n\n";
}

void printWinBanner() {
    std::cout << "/========================================================\\\n";
    std::cout << "||  __   __ ___   _   _  __        __ ___  _   _   _    ||\n";
    std::cout << "||  \\ \\ / // _ \\ | | | | \\ \\      / /|_ _|| \\ | | | |   ||\n";
    std::cout << "||   \\ V /| | | || | | |  \\ \\ /\\ / /  | | |  \\| | | |   ||\n";
    std::cout << "||    | | | |_| || |_| |   \\ V  V /   | | | |\\  | |_|   ||\n";
    std::cout << "||    |_|  \\___/  \\___/     \\_/\\_/   |___||_| \\_| (_)   ||\n";
    std::cout << "\\========================================================/\n";
}

void printLoseBanner() {
    std::cout << "/==============================================================\\\n";
    std::cout << "||  __   __ ___   _   _   _      ___   ____   _____   _  _    ||\n";
    std::cout << "||  \\ \\ / // _ \\ | | | | | |    / _ \\ / ___| | ____| | || |   ||\n";
    std::cout << "||   \\ V /| | | || | | | | |   | | | |\\___ \\ |  _|   | || |   ||\n";
    std::cout << "||    | | | |_| || |_| | | |___| |_| | ___) || |___  |_||_|   ||\n";
    std::cout << "||    |_|  \\___/  \\___/  |_____|\\___/ |____/ |_____| (_)(_)   ||\n";
    std::cout << "\\==============================================================/\n";
}

void printGameOverBanner() {
    std::cout << "/====================================================================\\\n";
    std::cout << "||    ____     _     __  __  _____    ___ __     __ _____  ____     ||\n";
    std::cout << "||   / ___|   / \\   |  \\/  || ____|  / _ \\\\ \\   / /| ____||  _ \\    ||\n";
    std::cout << "||  | |  _   / _ \\  | |\\/| ||  _|   | | | |\\ \\ / / |  _|  | |_) |   ||\n";
    std::cout << "||  | |_| | / ___ \\ | |  | || |___  | |_| | \\ V /  | |___ |  _ <    ||\n";
    std::cout << "||   \\____|/_/   \\_\\|_|  |_||_____|  \\___/   \\_/   |_____||_| \\_\\   ||\n";
    std::cout << "\\====================================================================/\n";
}

void printBustedBanner() {
    std::cout << "/================================================\\\n";
    std::cout << "||   ____   _   _  ____  _____  _____  ____     ||\n";
    std::cout << "||  | __ ) | | | |/ ___||_   _|| ____||  _ \\    ||\n";
    std::cout << "||  |  _ \\ | | | |\\___ \\  | |  |  _|  | | | |   ||\n";
    std::cout << "||  | |_) || |_| | ___) | | |  | |___ | |_| |   ||\n";
    std::cout << "||  |____/  \\___/ |____/  |_|  |_____||____/    ||\n";
    std::cout << "\\================================================/\n";
}

void printBlackjackBanner() {
    std::cout << R"(
.------------------------------------------------------------------------.
|.------..------..------..------..------..------..------..------..------.|
||B.--. ||L.--. ||A.--. ||C.--. ||K.--. ||J.--. ||A.--. ||C.--. ||K.--. ||
|| :(): || :/\: || (\/) || :/\: || :/\: || :(): || (\/) || :/\: || :/\: ||
|| ()() || (__) || :\/: || :\/: || :\/: || ()() || :\/: || :\/: || :\/: ||
|| '--'B|| '--'L|| '--'A|| '--'C|| '--'K|| '--'J|| '--'A|| '--'C|| '--'K||
|`------'`------'`------'`------'`------'`------'`------'`------'`------'|
'------------------------------------------------------------------------'
    )" << "\n\n";
}


// ---------------- Game Logic ----------------
int main() {
    printBanner();
    int credits = 1000;
    std::cout << "Welcome to Blackjack! You start with 1000 credits.\n";

    bool playing = true;
    while (playing && credits > 0) {
        std::cout << "\nCredits: " << credits << "\n";
        std::cout << "Enter bet: ";
        int bet;
        std::cin >> bet;
        if (bet <= 0 || bet > credits) {
            std::cout << "Invalid bet.\n";
            continue;
        }
        std::cout << "[DEBUG] Player bet = " << bet << "\n";

        Deck deck;
        std::vector<Card> dealer;
        std::vector<std::vector<Card>> playerHands;
        playerHands.push_back({ deck.draw(), deck.draw() });
        dealer.push_back(deck.draw());
        dealer.push_back(deck.draw());

        std::cout << "Your hand: ";
        printHand(playerHands[0]);
        std::cout << "Dealer hand: ";
        printHand(dealer, true);

        int playerVal = handValue(playerHands[0]);
        int dealerVal = handValue(dealer);

        if (playerVal == 21 && dealerVal == 21) {
            std::cout << "Both have Blackjack! Push.\n";
            continue;
        }
        else if (playerVal == 21) {
            printBlackjackBanner();
            std::cout << "Blackjack! You win 1.5x your bet.\n";
            credits += (int)(bet * 1.5);
            continue;
        }
        else if (dealerVal == 21) {
            printLoseBanner();
            std::cout << "Dealer Blackjack. You lose.\n";
            credits -= bet;
            continue;
        }

        bool splitAllowed = (playerHands[0][0].value == playerHands[0][1].value);
        std::vector<int> handBets(playerHands.size(), bet);

        // --------- Player Turn(s) ---------
        for (size_t handIndex = 0; handIndex < playerHands.size(); handIndex++) {
            bool handDone = false;
            bool doubledDown = false;

            while (!handDone) {
                int value = handValue(playerHands[handIndex]);
                std::cout << "\nYour hand: ";
                printHand(playerHands[handIndex]);
                std::cout << "Total: " << value << "\n";

                if (value > 21) {
                    printBustedBanner();
                    credits -= handBets[handIndex];
                    std::cout << "[DEBUG] Busted, lost " << handBets[handIndex]
                        << ", credits = " << credits << "\n";
                        handDone = true;
                        break;
                }

                std::cout << "[H]it, [S]tand";
                if (splitAllowed && playerHands.size() == 1) std::cout << ", S[p]lit";
                if (value == 9 || value == 10 || value == 11) std::cout << ", [D]ouble Down";
                std::cout << ", [X] Pass: ";

                char choice;
                std::cin >> choice;

                if (choice == 'H' || choice == 'h') {
                    playerHands[handIndex].push_back(deck.draw());
                }
                else if (choice == 'S' || choice == 's') {
                    handDone = true;
                }
                else if ((choice == 'P' || choice == 'p') && splitAllowed && playerHands.size() == 1) {
                    credits -= bet;
                    std::vector<Card> newHand;
                    newHand.push_back(playerHands[0][1]);
                    playerHands[0].pop_back();
                    playerHands.push_back(newHand);
                    playerHands[0].push_back(deck.draw());
                    playerHands[1].push_back(deck.draw());
                    handBets.push_back(bet);
                    handDone = true;
                }
                else if ((choice == 'D' || choice == 'd') && !doubledDown && (value == 9 || value == 10 || value == 11)) {
                    credits -= bet;
                    handBets[handIndex] *= 2;
                    playerHands[handIndex].push_back(deck.draw());
                    handDone = true;
                    doubledDown = true;
                }
                else if (choice == 'X' || choice == 'x') {
                    credits -= handBets[handIndex] / 2;
                    handDone = true;
                }
            }
        }

        // --------- Dealer Turn ---------
        std::cout << "\nDealer reveals: ";
        printHand(dealer);
        while (handValue(dealer) < 17) {
            dealer.push_back(deck.draw());
        }
        int dealerTotal = handValue(dealer);
        std::cout << "Dealer total: " << dealerTotal << "\n";

        // --------- Compare Results ---------
        for (size_t handIndex = 0; handIndex < playerHands.size(); handIndex++) {
            int value = handValue(playerHands[handIndex]);
            if (value > 21) continue;

            if (dealerTotal > 21 || value > dealerTotal) {
                printWinBanner();
                credits += handBets[handIndex];
            }
            else if (value == dealerTotal) {
                std::cout << "Push.\n";
            }
            else {
                printLoseBanner();
                credits -= handBets[handIndex];
            }
        }

        if (credits <= 0) {
            printGameOverBanner();
            std::cout << "You're out of credits! Game over.\n";
            break;
        }

        std::cout << "\nPlay again? (y/n): ";
        char again;
        std::cin >> again;
        if (again != 'y' && again != 'Y') {
            playing = false;
        }
    }

    std::cout << "Thanks for playing! Final credits: " << credits << "\n";
    return 0;
}
