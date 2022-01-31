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



namespace ING {

	class Thread;



	class ING_API ApplicationThreadManager :
		public Singleton<ApplicationThreadManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationThreadManager();
		~ApplicationThreadManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	Thread Management
		 */
	private:
		Thread* renderingThread;
		Thread* physicsThread;

	public:
		Thread* GetRenderingThread () { return renderingThread; }
		Thread* GetPhysicsThread () { return physicsThread; }



		/**
		 *	StartFrame, EndFrame Method
		 */
	public:
		void StartFrame();
		void EndFrame();

	};

}