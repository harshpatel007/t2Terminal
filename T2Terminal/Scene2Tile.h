#pragma once
/*
* @author: Rushabh Parakh
* @mailto: rgparakh@gmail.com
* please dont remove @author or modify it.
* any changes or bug fixes are done please annotate the locations where bug fixed.
*/

#pragma once
#ifndef  _SCENE2TILE_H_
#define _SCENE2TILE_H_

#include"IScene.h"
#include "FloorTexture.h"

#define TILE_SIDE 20.0f
#define TRANS_Y_SCENE_2_TILE -7.0f
#define TRANS_Y_SIDEWALL_SCENE_2_TILE -3.0f


namespace Rushabh
{

	class  Scene2Tile : virtual public T2Terminal::IScene
	{
	public:

		Scene2Tile();


		~Scene2Tile();

	public:

		GLuint _vertexShaderObject;
		GLuint _fragmentShaderObject;

		GLfloat angle;

		GLuint vbo_position;
		GLuint vbo_texture;

	protected:
		GLuint vao;

		GLuint _shaderProgramObject;

		mat4 _perspectiveProjectionMatrix;

		GLuint _modelMatrixUniform;
		GLuint _ViewMatrixUniform;
		GLuint _projectMatrixUniform;
		GLuint _MVPUniform;

		GLuint _LaUniform;
		GLuint _LdUniform;
		GLuint _LsUniform;
		GLuint _LightPositionUniform;
		GLuint _KaUniform;
		GLuint _KdUniform;
		GLuint _KsUniform;
		GLuint material_shininess_uniform;

		GLuint gVao_Floor;
		GLuint gVbo_Floor_position;
		GLuint gVbo_Floor_texture;
		GLuint _Texture_sampler_uniform;
		GLuint gTexture_Floor;
		GLuint gTexture_SideWall;
		GLuint gTexture_BackWall;

	private :

		int LoadGLTextures(GLuint *, TCHAR[]);

	public:

		virtual BOOL SceneHandler(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) override;

		virtual void Initialize() override;

		virtual void Update() override;

		virtual void ReSize(int width, int height, struct ResizeAttributes attributes) override;

		virtual void Render(HDC hdc, struct Attributes attributes) override;

		virtual void SceneTransition() override;

		virtual void UnInitialize() override;

	};
}


#endif // ! _SCENE2TILE_H_
