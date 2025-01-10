#include "lab_work_manager.hpp"
#include "imgui.h"
#include "lab_work_1/lab_work_1.hpp"
#include "lab_work_2/lab_work_2.hpp"
<<<<<<< HEAD
#include "lab_work_3/lab_work_3.hpp"
#include "lab_work_4/lab_work_4.hpp"
#include "lab_work_5/lab_work_5.hpp"
#include "lab_work_6/lab_work_6.hpp"

=======
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
namespace M3D_ISICG
{
	LabWorkManager::LabWorkManager()
	{
<<<<<<< HEAD
		_current = new LabWork1();
		_type	 = TYPE::LAB_WORK_1;
=======
		_current = new LabWork2();
		_type	 = TYPE::LAB_WORK_2;
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}

	void LabWorkManager::drawMenu()
	{
<<<<<<< HEAD
		if ( ImGui ::MenuItem( "tp1" ) )
		{
			if ( _type != TYPE ::LAB_WORK_1 )
			{
				const int w = _current->getWindowWidth();
				const int h = _current->getWindowHeight();
				delete _current;
				_current = new LabWork1();
				_type	 = TYPE ::LAB_WORK_1;
				_current->resize( w, h );
				_current->init();
			}
		}

		if ( ImGui ::MenuItem( "tp2" ) )
		{
			if ( _type != TYPE ::LAB_WORK_2 )
			{
				const int w = _current->getWindowWidth();
				const int h = _current->getWindowHeight();
				delete _current;
				_current = new LabWork2();
				_type	 = TYPE ::LAB_WORK_2;
				_current->resize( w, h );
				_current->init();
			}
		}

		if ( ImGui ::MenuItem( "tp3" ) )
		{
			if ( _type != TYPE ::LAB_WORK_3 )
			{
				// Keep window size .
				const int w = _current->getWindowWidth();
				const int h = _current->getWindowHeight();
				delete _current;
				_current = new LabWork3();
				_type	 = TYPE ::LAB_WORK_3;
				_current->resize( w, h );
				_current->init();
			}
		}

		if ( ImGui ::MenuItem( "tp4" ) )
		{
			if ( _type != TYPE ::LAB_WORK_4 )
			{
				const int w = _current->getWindowWidth();
				const int h = _current->getWindowHeight();
				delete _current;
				_current = new LabWork4();
				_type	 = TYPE ::LAB_WORK_4;
				_current->resize( w, h );
				_current->init();
			}
		}

		if ( ImGui ::MenuItem( "tp5" ) )
		{
			if ( _type != TYPE ::LAB_WORK_5 )
			{
				// Keep window size .
				const int w = _current->getWindowWidth();
				const int h = _current->getWindowHeight();
				delete _current;
				_current = new LabWork5();
				_type	 = TYPE ::LAB_WORK_5;
				_current->resize( w, h );
				_current->init();
			}
		}

		if ( ImGui ::MenuItem( "tp 6" ) )
		{
			if ( _type != TYPE ::LAB_WORK_6 )
			{
				const int w = _current->getWindowWidth();
				const int h = _current->getWindowHeight();
				delete _current;
				_current = new LabWork6();
				_type	 = TYPE ::LAB_WORK_6;
				_current->resize( w, h );
				_current->init();
			}
		}
=======
		// Here you can add other lab works to the menu.
		/* if ( ImGui::MenuItem( "Lab work 1" ) )
		{
			if ( _type != TYPE::LAB_WORK_1 ) // Change only if needed.
			{
				// Keep window size.
				const int w = _current->getWindowWidth();
				const int h = _current->getWindowHeight();
				delete _current;			 // Delete old lab work.
				_current = new LabWork1();	 // Create new lab work.
				_type	 = TYPE::LAB_WORK_1; // Update type.
				_current->resize( w, h );	 // Update window size.
				_current->init();			 // Don't forget to call init().
			}
		}*/
		if ( ImGui ::MenuItem( "Lab work 2" ) )
		{
			if ( _type != TYPE ::LAB_WORK_2 ) // Change only if needed .
			{
				// Keep window size .
				const int w = _current -> getWindowWidth();
				const int h = _current -> getWindowHeight();
				delete _current;			  // Delete old lab work .
				_current = new LabWork2();	  // Create new lab work .
				_type	 = TYPE ::LAB_WORK_2; // Update type .
				_current -> resize( w, h );  // Update window size .
				_current -> init();		  // Don ’t forget to call init ().
			}
		}
		
>>>>>>> a4d137c3975a7b4395253c3714773028d4bbc290
	}
} // namespace M3D_ISICG
