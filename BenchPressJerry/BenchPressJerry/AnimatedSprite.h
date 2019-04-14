#pragma once

#include "BasicSprite.h"

class AnimatedSprite : public BasicSprite
{
public:
	AnimatedSprite();
	~AnimatedSprite();

	void Initialize(const Microsoft::WRL::ComPtr<ID3D11Device1> d3dDevice, const wchar_t* fileName, uint16_t x = 0, uint16_t y = 0, uint16_t width = 0, uint16_t height = 0, signed short frameColumnCount = 1, signed short frameRowCount = 1, float animSpeed = 1.0f);
	void Update(float dt);
	void Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch) override;

private:
	void UpdateSourceRect();

	signed short m_frameIndex = 0;
	signed short m_frameColumnCount = 1;
	signed short m_frameRowCount = 1;

	float m_animTime = 0.0f;
	float m_animSpeed = 1.0f;

	signed short m_frameWidth = 0;
	signed short m_frameHeight = 0;

	RECT m_sourceRect;
};