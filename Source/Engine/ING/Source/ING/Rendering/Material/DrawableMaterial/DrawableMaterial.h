#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Rendering Material
 */
#include <ING/Rendering/Material/Material.h>



/**
 *	Include Transform
 */
#include <ING/Transform/Transform.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class C_DrawableCategory;

		class IDrawble;

		class IShader;

		class IState;



		class ING_API DrawableMaterial : public IMaterial
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			DrawableMaterial	(const String& name, IShader* shader);
			~DrawableMaterial	();



			/**
			 *	Methods
			 */
		public:
			virtual void Apply	(const String& passName) override;

			virtual void ApplyTransform (const S_TransformM& transformMatrices);
			virtual void ApplyTransform (const S_TransformM& transformMatrices, bool updateBuffer);

			virtual void ApplyCamera	(Camera* camera);
			virtual void ApplyCamera	(Camera* camera, bool updateBuffer);

		};

	}

}