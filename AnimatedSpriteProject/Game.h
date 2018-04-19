//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include "AnimatedTexture.h"
#include "ScrollingBackground.h"
#include "Player.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;
	bool											m_fireWeapon;
	float											m_timeFired;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext;

    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	std::unique_ptr<Player> m_player;
	std::shared_ptr<AnimatedTexture> m_playerShipTexture;
	std::shared_ptr<AnimatedTexture> m_playerWeaponTexture;

	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_shipTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_weaponTexture;
	DirectX::SimpleMath::Vector2 m_shipPos;
	DirectX::SimpleMath::Vector2 m_weaponPos;

	std::unique_ptr<ScrollingBackground> m_stars;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_backgroundTex;

	std::unique_ptr<DirectX::Keyboard> m_keyboard;
};