#include "triangle_mesh.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <iostream>

namespace M3D_ISICG
{
	TriangleMesh::TriangleMesh( const std::string &				  p_name,
								const std::vector<Vertex> &		  p_vertices,
								const std::vector<unsigned int> & p_indices,
								const Material &				  p_material ) :
		_name( p_name ),
		_vertices( p_vertices ), _indices( p_indices ), _material( p_material )
	{
<<<<<<< HEAD
		// Optimisation des vecteurs pour économiser de la mémoire
		_vertices.shrink_to_fit();
		_indices.shrink_to_fit();

		// Initialisation OpenGL
		setupGL();
=======
		_vertices.shrink_to_fit();
		_indices.shrink_to_fit();
		_setupGL();
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	void TriangleMesh::render( const GLuint p_glProgram ) const
	{
<<<<<<< HEAD
		// Activation du programme shader
		glUseProgram( p_glProgram );

		// Transmission du flag indiquant la présence d'une texture diffuse
		glUniform1i( glGetUniformLocation( p_glProgram, "uHasDiffuseMap" ), _material._hasDiffuseMap ? 1 : 0 );

		if ( _material._hasDiffuseMap )
		{
			// Liaison de la texture diffuse à l'unité de texture 1
			glBindTextureUnit( 1, _material._diffuseMap._id );
		}

		// Transmission de la couleur diffuse par défaut
		glUniform3fv( glGetUniformLocation( p_glProgram, "uDiffuseColor" ), 1, glm::value_ptr( _material._diffuse ) );

		// Calcul et transmission de la direction de la lumière
		glm::vec3 lightDirection = glm::normalize( glm::vec3( 0.0f, 0.0f, -1.0f ) );
		glUniform3fv( glGetUniformLocation( p_glProgram, "uLightDirection" ), 1, glm::value_ptr( lightDirection ) );

		// Dessin du maillage
		glBindVertexArray( _vao );
		glDrawElements( GL_TRIANGLES, static_cast<GLsizei>( _indices.size() ), GL_UNSIGNED_INT, 0 );
		glBindVertexArray( 0 );

		// Déliaison de la texture après le rendu
		if ( _material._hasDiffuseMap )
		{
			glBindTextureUnit( 1, 0 );
		}

		// Désactivation du programme shader
		glUseProgram( 0 );
=======
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	void TriangleMesh::cleanGL()
	{
<<<<<<< HEAD
		// Désactivation des attributs vertex
		glDisableVertexArrayAttrib( _vao, 0 );
		glDisableVertexArrayAttrib( _vao, 1 );

		// Suppression des ressources OpenGL
=======
		glDisableVertexArrayAttrib( _vao, 0 );
		glDisableVertexArrayAttrib( _vao, 1 );
		glDisableVertexArrayAttrib( _vao, 2 );
		glDisableVertexArrayAttrib( _vao, 3 );
		glDisableVertexArrayAttrib( _vao, 4 );
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
		glDeleteVertexArrays( 1, &_vao );
		glDeleteBuffers( 1, &_vbo );
		glDeleteBuffers( 1, &_ebo );
	}

<<<<<<< HEAD
	void TriangleMesh::setupGL()
	{
		// Génération des objets OpenGL (VAO, VBO, EBO)
		glGenVertexArrays( 1, &_vao );
		glGenBuffers( 1, &_vbo );
		glGenBuffers( 1, &_ebo );

		// Configuration du VAO
		glBindVertexArray( _vao );

		// Chargement des données de sommets dans le VBO
		glBindBuffer( GL_ARRAY_BUFFER, _vbo );
		glBufferData( GL_ARRAY_BUFFER, _vertices.size() * sizeof( Vertex ), _vertices.data(), GL_STATIC_DRAW );

		// Chargement des indices dans l'EBO
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _ebo );
		glBufferData(
			GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof( unsigned int ), _indices.data(), GL_STATIC_DRAW );

		// Configuration des attributs vertex : position
		glEnableVertexAttribArray( 0 );
		glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void *)offsetof( Vertex, _position ) );

		// Configuration des attributs vertex : normales
		glEnableVertexAttribArray( 1 );
		glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void *)offsetof( Vertex, _normal ) );

		// Configuration des attributs vertex : coordonnées de texture
		glEnableVertexAttribArray( 2 );
		glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void *)offsetof( Vertex, _texCoords ) );

		// Déliaison du VAO
		glBindVertexArray( 0 );
	}

=======
	void TriangleMesh::_setupGL()
	{		
	}
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
} // namespace M3D_ISICG
