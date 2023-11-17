#include "Engine.h"

Engine::Engine()
{
	// Get the screen resolution and create and SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y), "Thomas was late", Style::Fullscreen);

	// Initialize the full screen view
	m_MainView.setSize(resolution);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	// Initialize the split-screen views
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::run() 
{
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		// Update the total time
		m_GameTimeTotal += dt;
		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}