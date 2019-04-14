#pragma once

/*Class for rendering a basic image to the screen.*/
class BasicSprite
{
public:
	BasicSprite();
	virtual ~BasicSprite();

	virtual void Initialize(const Microsoft::WRL::ComPtr<ID3D11Device1> d3dDevice, const wchar_t* fileName, uint16_t x = 0, uint16_t y = 0, uint16_t width = 0, uint16_t height = 0);
	virtual void CleanUp();
	virtual void Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);

	virtual void SetPositionAndSize(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
	virtual void SetPosition(uint16_t x, uint16_t y);
	virtual void SetSize(uint16_t width, uint16_t height);
	virtual void SetX(uint16_t x);
	virtual void SetY(uint16_t y);
	virtual void SetWidth(uint16_t width);
	virtual void SetHeight(uint16_t height);

protected:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_resource;
	RECT m_rect;
};