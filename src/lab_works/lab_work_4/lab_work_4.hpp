#ifndef LAB_WORK_4_HPP
#define LAB_WORK_4_HPP

#include "common/base_lab_work.hpp"
#include "common/models/triangle_mesh_model.hpp"
#include <common/camera.hpp>

namespace M3D_ISICG
{
	class LabWork4 : public BaseLabWork
	{
	  public:
		LabWork4() : BaseLabWork() {}
		~LabWork4() override = default;

		float _cameraSpeed		 = 0.1f;
		float _cameraSensitivity = 0.1f;

		bool init() override;
		void animate( const float p_deltaTime ) override {}
		void render() override;

		void displayUI() override;
		void handleEvents( const SDL_Event & p_event ) override;

	  private:
		TriangleMeshModel _triangleMeshModel;
		Camera			  _camera;
		TriangleMeshModel _bunnyModel;
		TriangleMeshModel _conferenceModel;
		GLuint			  _program = 0;
		glm::mat4		  _modelMatrix;
		GLuint			  _shaderProgram;
		glm::vec3		  _lightDirection;
	};
} // namespace M3D_ISICG

#endif // LAB_WORK_4_HPP
