#pragma once
#include "Window.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ConstantBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "InputListener.h"
#include "Mat4.h"

class AppWindow : public Window, public InputListener
{
public:
	AppWindow();
	~AppWindow();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
	virtual void onFocus() override;
	virtual void onKillFocus() override;

	// Inherited via InputListener
	virtual void onKeyDown(int key) override;
	virtual void onKeyUp(int key) override;
	virtual void onMouseMove(const Point& mouse_pos) override;
	virtual void onLeftMouseDown(const Point& mouse_pos) override;
	virtual void onRightMouseDown(const Point& mouse_pos) override;
	virtual void onLeftMouseUp(const Point& mouse_pos) override;
	virtual void onRightMouseUp(const Point& mouse_pos) override;

	void update();
	void updateModel();
	void updateCamera();
	void updateSkybox();
	void drawMesh(const MeshPtr& mesh, const VertexShaderPtr& vs, const PixelShaderPtr& ps, 
		ConstantBufferPtr& cb, const TexturePtr& tex);

private:
	SwapChainPtr m_swap_chain;
	VertexBufferPtr m_vb;
	IndexBufferPtr m_ib;
	VertexShaderPtr m_vs;
	PixelShaderPtr m_ps;
	PixelShaderPtr m_sky_ps;
	ConstantBufferPtr m_cb;
	ConstantBufferPtr m_sky_cb;

	TexturePtr m_tex;
	TexturePtr m_sky_tex;

	MeshPtr m_mesh;
	MeshPtr m_sky_mesh;;

	long m_old_delta;
	long m_new_delta;
	float m_delta_time;

	float m_delta_pos;
	float m_delta_scale;
	float m_delta_rot;

	Mat4 m_world_cam;
	Mat4 m_view;
	Mat4 m_proj_view;

	float m_forward = 0.0f;
	float m_right = 0.0f;

	float m_rot_x = 0.0f;
	float m_rot_y = 0.0f;

	float m_light_rot_y = 0.0f;

	float m_scale = 1;

	float m_cam_speed = 0.03f;
};