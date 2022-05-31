#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	class IApplication;

	namespace UI {

		class Node;

		class C_Element;

		class C_Canvas;

	}

	class ING_API ApplicationUISystem : public IApplicationComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationUISystem		(IApplication* application);
		~ApplicationUISystem	();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init();
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		std::unordered_map<String, UI::C_Canvas*> name2CanvasMap;

	public:
		UI::C_Canvas*	GetCanvas	(const String& name) { 

			if (!IsHasCanvas(name)) return 0;
			
			return name2CanvasMap[name];
		}

		bool			IsHasCanvas	(const String& name) { return name2CanvasMap.find(name) != name2CanvasMap.end(); }



		/**
		 *	Methods
		 */
	public:
		void			AddCanvas	(UI::C_Canvas* canvas);
		void			RemoveCanvas(UI::C_Canvas* canvas);

		virtual void	Start		() override;

		virtual void	PreUpdate	() override;
		virtual void	Update		() override;
		virtual void	LateUpdate	() override;

		virtual void	PreRender	() override;
		virtual void	Render		() override;
		virtual void	LateRender	() override;

	};

}