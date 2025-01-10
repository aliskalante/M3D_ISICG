<<<<<<< HEAD
#include "lab_work_3.hpp"
#include "common/camera.hpp"
#include "utils/read_file.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
=======
#include "imgui.h"
#include "lab_work_3.hpp"
#include "utils/read_file.hpp"
#include <glm/gtc/type_ptr.hpp>
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
#include <iostream>

namespace M3D_ISICG
{
<<<<<<< HEAD
	const std::string LabWork3::_shaderFolder = "src/lab_works/lab_work_3/shaders/";

	LabWork3::~LabWork3()
	{
		glDeleteVertexArrays( 1, &_cube.vertexArray );
		glDeleteBuffers( 1, &_cube.positionBuffer );
		glDeleteBuffers( 1, &_cube.colorBuffer );
		glDeleteBuffers( 1, &_cube.elementBuffer );
		glDeleteProgram( _shaderProgram );
=======
	const std::string LabWork3::_shaderFolder = "src/lab_works/lab_work_2/shaders/";
	GLuint			  program3				  = GL_INVALID_INDEX;
	

	GLuint			  vboCol;
	GLint			  uTranslationXLocation;
	GLint			  luminositeLocation;
	GLfloat			  time		 = 0.0f;
	GLfloat			  luminosite = 1.0f;
	
	LabWork3::~LabWork3()
	{
		glDeleteProgram( program3 );
		glDeleteBuffers( 1, &vbo3 );
		glDisableVertexArrayAttrib( vao3, 0 );
		glDeleteVertexArrays( 1, &vao3 );
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	bool LabWork3::init()
	{
<<<<<<< HEAD
		std::cout << "Initializing LabWork3..." << std::endl;

		// Charger les shaders et créer le programme
		_loadShaders();

		// Initialiser le cube (positions, couleurs, indices)
		_initializeCubeData();
		_configureBuffers();

		// Configurer les matrices (vue, projection)
		_viewMatrix = glm::lookAt(
			glm::vec3( 2.0f, 2.0f, 2.0f ), glm::vec3( 0.0f, 0.0f, 0.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
		_updateViewMatrix();

		_projectionMatrix = glm::perspective( glm::radians( 45.0f ), 1280.0f / 720.0f, 0.1f, 100.0f );
		_updateProjectionMatrix();

		// Activer le test de profondeur
		glEnable( GL_DEPTH_TEST );

		std::cout << "Initialization complete!" << std::endl;
		return true;
	}

	void LabWork3::_loadShaders()
	{
		const std::string vertexCode   = readFile( _shaderFolder + "lw3.vert" );
		const std::string fragmentCode = readFile( _shaderFolder + "lw3.frag" );

		GLuint		 vertexShader = glCreateShader( GL_VERTEX_SHADER );
		const char * vSource	  = vertexCode.c_str();
		glShaderSource( vertexShader, 1, &vSource, nullptr );
		glCompileShader( vertexShader );

		GLuint		 fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
		const char * fSource		= fragmentCode.c_str();
		glShaderSource( fragmentShader, 1, &fSource, nullptr );
		glCompileShader( fragmentShader );

		_shaderProgram = glCreateProgram();
		glAttachShader( _shaderProgram, vertexShader );
		glAttachShader( _shaderProgram, fragmentShader );
		glLinkProgram( _shaderProgram );

		glDeleteShader( vertexShader );
		glDeleteShader( fragmentShader );

		// Obtenir les emplacements des matrices
		_uModelMatrixLoc	  = glGetUniformLocation( _shaderProgram, "uModelMatrix" );
		_uViewMatrixLoc		  = glGetUniformLocation( _shaderProgram, "uViewMatrix" );
		_uProjectionMatrixLoc = glGetUniformLocation( _shaderProgram, "uProjectionMatrix" );
	}

	void LabWork3::_initializeCubeData()
	{
		_cube.positions
			= { { -0.5f, -0.5f, -0.5f }, { 0.5f, -0.5f, -0.5f }, { 0.5f, 0.5f, -0.5f }, { -0.5f, 0.5f, -0.5f },
				{ -0.5f, -0.5f, 0.5f },	 { 0.5f, -0.5f, 0.5f },	 { 0.5f, 0.5f, 0.5f },	{ -0.5f, 0.5f, 0.5f } };

		for ( size_t i = 0; i < _cube.positions.size(); ++i )
		{
			_cube.colors.push_back( getRandomVec3f() );
		}

		_cube.indices = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 0, 4, 7, 0, 7, 3,
						  1, 5, 6, 1, 6, 2, 3, 2, 6, 3, 6, 7, 0, 1, 5, 0, 5, 4 };
	}

	void LabWork3::_configureBuffers()
	{
		glCreateBuffers( 1, &_cube.positionBuffer );
		glNamedBufferData(
			_cube.positionBuffer, _cube.positions.size() * sizeof( Vec3f ), _cube.positions.data(), GL_STATIC_DRAW );

		glCreateBuffers( 1, &_cube.colorBuffer );
		glNamedBufferData(
			_cube.colorBuffer, _cube.colors.size() * sizeof( Vec3f ), _cube.colors.data(), GL_STATIC_DRAW );

		glCreateBuffers( 1, &_cube.elementBuffer );
		glNamedBufferData(
			_cube.elementBuffer, _cube.indices.size() * sizeof( unsigned int ), _cube.indices.data(), GL_STATIC_DRAW );

		glCreateVertexArrays( 1, &_cube.vertexArray );

		glVertexArrayVertexBuffer( _cube.vertexArray, 0, _cube.positionBuffer, 0, sizeof( Vec3f ) );
		glVertexArrayAttribFormat( _cube.vertexArray, 0, 3, GL_FLOAT, GL_FALSE, 0 );
		glEnableVertexArrayAttrib( _cube.vertexArray, 0 );

		glVertexArrayVertexBuffer( _cube.vertexArray, 1, _cube.colorBuffer, 0, sizeof( Vec3f ) );
		glVertexArrayAttribFormat( _cube.vertexArray, 1, 3, GL_FLOAT, GL_FALSE, 0 );
		glEnableVertexArrayAttrib( _cube.vertexArray, 1 );

		glVertexArrayElementBuffer( _cube.vertexArray, _cube.elementBuffer );
	}

	void LabWork3::animate( const float deltaTime )
	{
		_modelMatrix = glm::rotate( _modelMatrix, glm::radians( 20.0f * deltaTime ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
		_updateModelMatrix();
=======
		struct Mesh
		{
			std::vector<Vec3f> vectSommets;
			std::vector<Vec3f> vectColor;
			unsigned int	   indice;
			glm::mat4		   matTransfer;
			Gluint vbo3

		};
		std::vector<Vec2f> vect;
		std::vector<int>   vect_indice;
		std::vector<float> vect_couleur;
		const std::string  vertexShaderStr	 = readFile( _shaderFolder + "lw3.vert" );
		const std::string  fragmentShaderStr = readFile( _shaderFolder + "lw3.frag" );
		std::cout << "Initializing lab work 3..." << std::endl;
		GLuint		   vertexShader = glCreateShader( GL_VERTEX_SHADER );
		const GLchar * vSrc			= vertexShaderStr.c_str();

		glShaderSource( vertexShader, 1, &vSrc, NULL );

		GLuint		   fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
		const GLchar * fSrc			  = fragmentShaderStr.c_str();
		glShaderSource( fragmentShader, 1, &fSrc, NULL );

		glCompileShader( fragmentShader );
		glCompileShader( vertexShader );
		GLint compiled;
		glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &compiled );

		if ( !compiled )
		{
			GLchar log[ 1024 ];
			glGetShaderInfoLog( vertexShader, sizeof( log ), NULL, log );
			glDeleteShader( vertexShader );
			glDeleteShader( fragmentShader );
			std ::cerr << " Error compiling vertex shader : " << log << std ::endl;
			return false;
		}
		program3 = glCreateProgram();
		glAttachShader( program3, vertexShader );
		glAttachShader( program3, fragmentShader );

		glLinkProgram( program3 );

		GLint linked;
		glGetProgramiv( program3, GL_LINK_STATUS, &linked );
		if ( !linked )
		{
			GLchar log[ 1024 ];
			glGetProgramInfoLog( program3, sizeof( log ), NULL, log );
			std ::cerr << " Error linking program : " << log << std ::endl;
			return false;
		}

		vect.push_back( Vec2f( 0.5f, 0.5f ) );
		vect.push_back( Vec2f( -0.5f, 0.5f ) );
		vect.push_back( Vec2f( -0.5f, -0.5f ) );
		vect.push_back( Vec2f( 0.5f, -0.5f ) );

		glCreateBuffers( 1, &vbo3 );
		glNamedBufferData( vbo3, vect.size() * sizeof( Vec2f ), vect.data(), GL_STATIC_DRAW );

		glCreateVertexArrays( 1, &vao3 );
		glEnableVertexArrayAttrib( vao3, 0 ); // activer l'attribut avertexposition du vao
		glVertexArrayAttribFormat( vao3, 0, 2, GL_FLOAT, GL_FALSE, 0 );
		glVertexArrayVertexBuffer(
			vao3, 0, vbo3, 0, sizeof( float ) * 2 ); // associer lindex 0 au vbo qui contient les somment pour que
		// avertexposition prend chque foix un elemnt(sommet) de ce vbo
		glVertexArrayAttribBinding( vao3, 0, 0 );

		vect_indice.push_back( 0 );
		vect_indice.push_back( 1 );
		vect_indice.push_back( 2 );

		vect_indice.push_back( 3 );
		vect_indice.push_back( 2 );

		glCreateBuffers( 1, &ebo );
		glNamedBufferData( ebo, vect_indice.size() * sizeof( int ), vect_indice.data(), GL_STATIC_DRAW );
		glVertexArrayElementBuffer( vao3, ebo );

		vect_couleur = { 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f };
		glCreateBuffers( 1, &vboCol );
		glNamedBufferData( vboCol, vect_couleur.size() * sizeof( float ), vect_couleur.data(), GL_STATIC_DRAW );
		glEnableVertexArrayAttrib( vao3, 1 );
		glVertexArrayAttribFormat( vao3, 1, 3, GL_FLOAT, GL_FALSE, 0 );
		glVertexArrayVertexBuffer( vao3, 1, vbo3, 0, sizeof( float ) * 3 );
		glVertexArrayAttribBinding( vao3, 1, 1 );

		uTranslationXLocation = glGetUniformLocation( program3, "uTranslationX" );
		// Valeur arbitraire pour la translation, ici on choisit 0.2f
		glProgramUniform1f( program3, uTranslationXLocation, 0.2f );

		luminositeLocation = glGetUniformLocation( program3, "luminosite" );

		// Initialiser la luminosité
		glProgramUniform1f( program3, luminositeLocation, luminosite );

		glDeleteShader( vertexShader );
		glDeleteShader( fragmentShader );
		// Set the color used by glClear to clear the color buffer (in render()).
		glClearColor( _bgColor.x, _bgColor.y, _bgColor.z, _bgColor.w );

		std::cout << "Done!" << std::endl;
		return true;
	}

	void LabWork3::animate( const float p_deltaTime )
	{
		// Mettre à jour le temps total
		time += p_deltaTime;

		// Calculer une valeur entre -0.5 et 0.5 avec la fonction sin
		float translationX = 0.5f * glm::sin( time );

		// Assigner cette valeur à la variable uniform uTranslationX
		glProgramUniform1f( program3, uTranslationXLocation, translationX );
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	void LabWork3::render()
	{
<<<<<<< HEAD
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glUseProgram( _shaderProgram );
		glBindVertexArray( _cube.vertexArray );
		glDrawElements( GL_TRIANGLES, static_cast<GLsizei>( _cube.indices.size() ), GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );
		glUseProgram( 0 );
	}

	void LabWork3::handleEvents( const SDL_Event & event )
	{
		if ( event.type == SDL_KEYDOWN )
		{
			switch ( event.key.keysym.scancode )
			{
			case SDL_SCANCODE_W: _camera.moveFront( _cameraSpeed ); break;
			case SDL_SCANCODE_S: _camera.moveFront( -_cameraSpeed ); break;
			case SDL_SCANCODE_A: _camera.moveRight( -_cameraSpeed ); break;
			case SDL_SCANCODE_D: _camera.moveRight( _cameraSpeed ); break;
			default: break;
			}
			_updateViewMatrix();
		}
	}

	void LabWork3::displayUI()
	{
		ImGui::Begin( "Lab Work 3 Settings" );
		ImGui::End();
	}
=======
		glClear( GL_COLOR_BUFFER_BIT );
		glUseProgram( program3 );
		glBindVertexArray( vao3 );
		glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );
	}

	void LabWork3::handleEvents( const SDL_Event & p_event ) {}

	void LabWork3::displayUI()
	{
		ImGui::Begin( "Settings lab work 3" );
		// Créer un slider pour la luminosité (de 0 à 1)
		if ( ImGui::SliderFloat( "luminosite", &luminosite, 0.0f, 1.0f ) )
		{
			// Si la luminosité est modifiée, mettre à jour l'uniform dans le shader
			glProgramUniform1f( program3, luminositeLocation, luminosite );
		}

		// Palette de couleurs pour la couleur de fond
		if ( ImGui::ColorEdit3( "Background Color", glm::value_ptr( _bgColor ) ) )
		{
			// Mettre à jour la couleur de fond OpenGL
			glClearColor( _bgColor.x, _bgColor.y, _bgColor.z, _bgColor.w );
		}
		ImGui::End();
	}

>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
} // namespace M3D_ISICG
