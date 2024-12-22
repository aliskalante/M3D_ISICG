#include "imgui.h"
#include "lab_work_3.hpp"
#include "utils/read_file.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

namespace M3D_ISICG
{
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
	}

	bool LabWork3::init()
	{
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
	}

	void LabWork3::render()
	{
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

} // namespace M3D_ISICG
