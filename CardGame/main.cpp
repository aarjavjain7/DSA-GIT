
#include <iostream>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>

using namespace std;

struct Card
{
    string color;
    string shape;
    string number;
};

int main()
{
    Card c1;

    // Step 1: Ask for colour
    cout << "Choose card color (red or black): ";
    cin >> c1.color;

    transform(c1.color.begin(), c1.color.end(),
              c1.color.begin(), ::tolower);

    // Step 2: Ask for shape according to colour
    if (c1.color == "red")
    {
        cout << "Choose shape (hearts or diamonds): ";
        cin >> c1.shape;
    }
    else if (c1.color == "black")
    {
        cout << "Choose shape (clubs or spades): ";
        cin >> c1.shape;
    }
    else
    {
        cout << "Invalid color! Choose red or black." << endl;
        return 1;
    }

    transform(c1.shape.begin(), c1.shape.end(),
              c1.shape.begin(), ::tolower);

    // Validate the selected shape
    if (c1.color == "red" &&
        c1.shape != "hearts" && c1.shape != "diamonds")
    {
        cout << "Invalid shape! Red cards have hearts or diamonds." << endl;
        return 1;
    }

    if (c1.color == "black" &&
        c1.shape != "clubs" && c1.shape != "spades")
    {
        cout << "Invalid shape! Black cards have clubs or spades." << endl;
        return 1;
    }

    // Step 3: Ask for card number
    cout << "Choose card number (2-10, ace, jack, queen, king): ";
    cin >> c1.number;

    transform(c1.number.begin(), c1.number.end(),
              c1.number.begin(), ::tolower);

    // Check that the number is valid
    string validNumbers[] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "ace", "jack", "queen", "king"
    };

    bool valid = false;

    for (string number : validNumbers)
    {
        if (c1.number == number)
        {
            valid = true;
            break;
        }
    }

    if (!valid)
    {
        cout << "Invalid card number!" << endl;
        return 1;
    }

    // Step 4: Create the image filename
    string filename = "cards/" + c1.number + "_of_" + c1.shape + ".png";

    // Load the card image
    sf::Texture texture;

    if (!texture.loadFromFile(filename))
    {
        cout << "Image not found: " << filename << endl;
        return 1;
    }

    sf::Sprite sprite(texture);

    // Resize the card to fit the window
    float scale = min(450.0f / texture.getSize().x,
                      500.0f / texture.getSize().y);

    sprite.setScale({scale, scale});

    // Create the SFML window
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "My Card Game"
    );

    // Centre the card
    float cardWidth = texture.getSize().x * scale;
    float cardHeight = texture.getSize().y * scale;

    sprite.setPosition({
        (800.0f - cardWidth) / 2.0f,
        (600.0f - cardHeight) / 2.0f
    });

    // Display the selected card
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color(25, 80, 50));
        window.draw(sprite);
        window.display();
    }

    return 0;
}
