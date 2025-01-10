#ifndef __LAB_WORK_3_HPP__
#define __LAB_WORK_3_HPP__

#include "GL/gl3w.h"
#include "common/base_lab_work.hpp"
<<<<<<< HEAD
#include "common/camera.hpp"
#include "define.hpp"
#include "utils/random.hpp"
=======
#include "define.hpp"
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
#include <vector>

namespace M3D_ISICG
{
	class LabWork3 : public BaseLabWork
	{
	  public:
		LabWork3() : BaseLabWork() {}
		~LabWork3();

<<<<<<< HEAD
		float _cameraSpeed		 = 0.1f;
		float _cameraSensitivity = 0.1f;

		bool init() override;
		void render() override;
		void animate( const float deltaTime ) override;
		void handleEvents( const SDL_Event & event ) override;
		void displayUI() override;

	  private:
		// Champs liés à la caméra
		float  _fovy = 45.0f;
		Camera _camera;

		// Initialisation des éléments
		void _initializeCubeData();
		void _configureBuffers();
		void _loadShaders();
		void _updateModelMatrix();
		void _updateViewMatrix();
		void _updateProjectionMatrix();

		// Structure représentant un maillage 3D
		struct Mesh
		{
			std::vector<Vec3f>		  positions;
			std::vector<Vec3f>		  colors;
			std::vector<unsigned int> indices;
			GLuint					  vertexArray	 = GL_INVALID_INDEX;
			GLuint					  positionBuffer = GL_INVALID_INDEX;
			GLuint					  colorBuffer	 = GL_INVALID_INDEX;
			GLuint					  elementBuffer	 = GL_INVALID_INDEX;
		};

		Mesh _cube;

		// Programme et emplacements des uniformes
		GLuint _shaderProgram		 = GL_INVALID_INDEX;
		GLint  _uModelMatrixLoc		 = -1;
		GLint  _uViewMatrixLoc		 = -1;
		GLint  _uProjectionMatrixLoc = -1;

		// Matrices
		glm::mat4 _modelMatrix		= glm::mat4( 1.0f );
		glm::mat4 _viewMatrix		= glm::mat4( 1.0f );
		glm::mat4 _projectionMatrix = glm::mat4( 1.0f );
=======
		bool init() override;
		void animate( const float p_deltaTime ) override;
		void render() override;

		void handleEvents( const SDL_Event & p_event ) override;
		void displayUI() override;

	  private:
		// ================ Scene data.
		// ================

		// ================ GL data.
		// ================

		// ================ Settings.
		Vec4f _bgColor = Vec4f( 0.8f, 0.8f, 0.8f, 1.f ); // Background color
		// ================
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290

		static const std::string _shaderFolder;
	};
} // namespace M3D_ISICG

<<<<<<< HEAD
#endif // __LAB_WORK_3_HPP__
=======
#endif // __LAB_WORK_1_HPP__
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
