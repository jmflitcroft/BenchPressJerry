#include "pch.h"
#include "BasicSprite.h"

BasicSprite::BasicSprite()
{
}
BasicSprite::~BasicSprite()
{
}

void BasicSprite::Initialize(const Microsoft::WRL::ComPtr<ID3D11Device1> d3dDevice, const wchar_t* fileName, uint16_t x /* = 0*/, uint16_t y /*= 0*/, uint16_t width /*= 0*/, uint16_t height /*= 0*/)
{
	DX::ThrowIfFailed(DirectX::CreateWICTextureFromFile(d3dDevice.Get(), fileName, m_resource.GetAddressOf(), m_resourceView.ReleaseAndGetAddressOf()));

	SetPosition(x, y);
	SetSize(width, height);
}

void BasicSprite::CleanUp()
{
	m_resourceView.Reset();
	m_resource.Reset();
}

void BasicSprite::Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch)
{
	spriteBatch->Draw(m_resourceView.Get(), m_displayRect);
}

void BasicSprite::SetPositionAndSize(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
	SetPosition(x, y);
	SetSize(width, height);
}
void BasicSprite::SetPosition(uint16_t x, uint16_t y)
{
	SetX(x);
	SetY(y);
}
void BasicSprite::SetSize(uint16_t width, uint16_t height)
{
	SetWidth(width);
	SetHeight(height);
}
void BasicSprite::SetX(uint16_t x)
{
	m_displayRect.right -= m_displayRect.left;
	m_displayRect.left = x;
	m_displayRect.right += x;
}
void BasicSprite::SetY(uint16_t y)
{
	m_displayRect.bottom -= m_displayRect.top;
	m_displayRect.top = y;
	m_displayRect.bottom += y;
}
void BasicSprite::SetWidth(uint16_t width)
{
	m_displayRect.right = m_displayRect.left + width;
}
void BasicSprite::SetHeight(uint16_t height)
{
	m_displayRect.bottom = m_displayRect.top + height;
}