#include "Cards.h"
#include <algorithm>
#include <random>
#include <cstdlib>

// Define static constants for CardType
const string CardType::BOMB = "Bomb";
const string CardType::REINFORCEMENT = "Reinforcement";
const string CardType::BLOCKADE = "Blockade";
const string CardType::AIRLIFT = "Airlift";
const string CardType::DIPLOMACY = "Diplomacy";

// Card implementation
// Constructor that takes a CardType
Card::Card(const string &type)
{
    this->type = new string(type);
}

// Copy constructor
Card::Card(const Card &other)
{
    type = new string(*other.type);
}

// Assignment operator
Card &Card::operator=(const Card &other)
{
    if (this != &other)
    {
        delete type;
        type = new string(*other.type);
    }
    return *this;
}

// Destructor
Card::~Card()
{
    delete type;
}

// Get the type of the card
string Card::getType() const
{
    return *type;
}

// Play the card
void Card::play(Hand &hand, Deck &deck)
{
    // Remove the card from the hand
    hand.removeCard(*this);

    // Return the card to the deck
    deck.addCard(this);

    cout << "Played card of type: " << getType() << ". Card returned to the deck." << endl;
}



// friend operator to access private members
ostream &operator<<(ostream &out, const Card &card)
{
    out << "Card Type: " << *card.type;
    return out;
}

// Deck implementation
// Default constructor initializes a deck with all card types
Deck::Deck()
{
    cards.push_back(new Card(CardType::BOMB));
    cards.push_back(new Card(CardType::REINFORCEMENT));
    cards.push_back(new Card(CardType::BLOCKADE));
    cards.push_back(new Card(CardType::AIRLIFT));
    cards.push_back(new Card(CardType::DIPLOMACY));
}

// Copy constructor
Deck::Deck(const Deck &other)
{
    for (Card *card : other.cards)
    {
        cards.push_back(new Card(*card));
    }
}

// Assignment operator
Deck &Deck::operator=(const Deck &other)
{
    if (this != &other)
    {
        for (Card *card : cards)
            delete card;
        cards.clear();
        for (Card *card : other.cards)
        {
            cards.push_back(new Card(*card));
        }
    }
    return *this;
}

// Destructor
Deck::~Deck() {
    for (Card* card : cards) {
        delete card;
    }
}

Card *Deck::draw()
{
    if (cards.empty())
    {
        throw runtime_error("Deck is empty!");
    }

    // Seed the random number generator with a fixed value
    srand(7);

    // Shuffle the deck manually using a random index
    for (size_t i = 0; i < cards.size() - 1; ++i)
    {
        size_t j = i + rand() / (RAND_MAX / (cards.size() - i) + 1);
        swap(cards[i], cards[j]);
    }

    // Draw the last card
    Card *drawnCard = cards.back();
    cards.pop_back(); // Remove the card from the deck
    return drawnCard;
}

// Add a card back to the deck
void Deck::addCard(Card *card)
{
    cards.push_back(card);
}
// friend operator to access private members
ostream &operator<<(ostream &out, const Deck &deck)
{
    out << "Deck has " << deck.cards.size() << " cards.";
    return out;
}

// Hand implementation

// Default constructor
Hand::Hand() {}

// Copy constructor
Hand::Hand(const Hand &other)
{
    for (Card *card : other.handCards)
    {
        handCards.push_back(new Card(*card));
    }
}

// Assignment operator
Hand &Hand::operator=(const Hand &other)
{
    if (this != &other)
    {
        for (Card *card : handCards)
            delete card;
        handCards.clear();
        for (Card *card : other.handCards)
        {
            handCards.push_back(new Card(*card));
        }
    }
    return *this;
}

// Destructor
Hand::~Hand()
{}

// Add a card to the hand
void Hand::addCard(Card *card)
{
    handCards.push_back(card);
}

// Removes a card from the hand
void Hand::removeCard(const Card &card)
{
    auto it = find_if(handCards.begin(), handCards.end(), [&card](Card *c)
                      { return c->getType() == card.getType(); });

    if (it != handCards.end())
    {            
      handCards.erase(it); // Remove the card pointer from the vector
    }
}

// Method to play and remove the first card in hand
// void Hand::playFirstCard(Deck &deck)
// {
//     if (!handCards.empty())
//     {
//         // Get the first card
//         Card *cardToPlay = handCards.front();

//         // Play the card (handles removal from hand and returning to deck)
//         cardToPlay->play(*this, deck);
//     }
// }
void Hand::playFirstCard(Deck& deck) {
    if (!handCards.empty()) {
        // Get the first card
        Card* cardToPlay = handCards.front();

        // Remove card from hand without deleting
        handCards.erase(handCards.begin());

        // Play the card (transfer it back to the deck)
        cardToPlay->play(*this, deck);
    }
}


// Method to check if the hand is empty
bool Hand::isEmpty() const
{
    return handCards.empty();
}
// friend operator to access private members
ostream &operator<<(ostream &out, const Hand &hand)
{
    out << "Hand has " << hand.handCards.size() << " cards.";
    return out;
}
