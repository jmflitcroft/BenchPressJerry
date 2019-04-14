#include "pch.h"
#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::Initialize(const Microsoft::WRL::ComPtr<ID3D11Device1> d3dDevice, const wchar_t* fileName, uint16_t x /*= 0*/, uint16_t y /*= 0*/, uint16_t width /*= 0*/, uint16_t height /*= 0*/, signed short frameColumnCount /*= 1*/, signed short frameRowCount /*= 1*/, float animSpeed /*= 1.0f*/)
{
	BasicSprite::Initialize(d3dDevice, fileName, x, y, width, height);

	m_frameColumnCount = frameColumnCount;
	m_frameRowCount = frameRowCount;

	Microsoft::WRL::ComPtr<ID3D11Texture2D> texture2D;
	DX::ThrowIfFailed(m_resource.As(&texture2D));
	CD3D11_TEXTURE2D_DESC textureDesc;
	texture2D->GetDesc(&textureDesc);

	m_frameWidth = textureDesc.Width / m_frameColumnCount;
	m_frameHeight = textureDesc.Height / m_frameRowCount;

	m_animSpeed = animSpeed;

	UpdateSourceRect();
}

void AnimatedSprite::Update(float dt)
{
	m_animTime += dt * m_animSpeed;
	if (m_animTime >= 1.0f)
	{
		m_animTime = 0.0f;
		++m_frameIndex;
		if (m_frameIndex >= m_frameColumnCount * m_frameRowCount)
		{
			m_frameIndex = 0;
		}

		UpdateSourceRect();
	}
}

void AnimatedSprite::Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{
	spriteBatch->Draw(m_resourceView.Get(), m_displayRect, &m_sourceRect, DirectX::Colors::White, 0.0f, DirectX::XMFLOAT2(), DirectX::SpriteEffects_None, 0.0f);
}

void AnimatedSprite::UpdateSourceRect()
{
	m_sourceRect.left = (m_frameIndex % m_frameColumnCount) * m_frameWidth;
	m_sourceRect.top = (m_frameIndex / m_frameColumnCount) * m_frameHeight;
	m_sourceRect.right = m_sourceRect.left + m_frameWidth;
	m_sourceRect.bottom = m_sourceRect.top + m_frameHeight;
}