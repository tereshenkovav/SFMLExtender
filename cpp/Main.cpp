#include <SFML\Graphics.hpp>
#include <SFML\System\Clock.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include "Game.h"

// Подключаем SFML
#pragma comment (lib, "lib\\sfml-window.lib")
#pragma comment (lib, "lib\\sfml-system.lib")
#pragma comment (lib, "lib\\sfml-graphics.lib")
#pragma comment (lib, "lib\\sfml-main.lib")

int main()
{
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(600, 800), "Game");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    srand(time(NULL));
    Game game;
    sf::Clock clock;
    float lasttime = clock.getElapsedTime().asSeconds();
    // Запуск главного цикла игры
    while (window.isOpen()) {
        // Обновляем состояние игры
        float newtime = clock.getElapsedTime().asSeconds();
        game.Update(window, newtime - lasttime);
        lasttime = newtime;
        /* Минимальный цикл событий*/
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) window.close();			
		}
	}

        // Выводим игру на экран
        window.clear();
        game.Render(window);
        window.display();
    }
    return 0;
}

