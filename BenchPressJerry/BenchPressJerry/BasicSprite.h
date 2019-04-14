#pragma once

/*Class for rendering a basic image to the screen.*/
class BasicSprite
{
public:
	void Initialize(const Microsoft::WRL::ComPtr<ID3D11Device1> d3dDevice, const wchar_t* fileName, uint16_t x = 0, uint16_t y = 0, uint16_t width = 0, uint16_t height = 0);
	void CleanUp();
	void Render(const std::unique_ptr<DirectX::SpriteBatch>& spriteBatch);

	void SetPositionAndSize(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
	void SetPosition(uint16_t x, uint16_t y);
	void SetSize(uint16_t width, uint16_t height);
	void SetX(uint16_t x);
	void SetY(uint16_t y);
	void SetWidth(uint16_t width);
	void SetHeight(uint16_t height);

private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_resource;
	RECT m_rect;
};