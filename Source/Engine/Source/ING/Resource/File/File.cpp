
/**
 *	Include Header
 */
#include "File.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Resource Manager
 */
#include <ING/Resource/Manager/Manager.h>



namespace ING {

	/**
	 *
	 *	File Loader
	 *
	 */

	/**
	 *	Constructors And Destructor
	 */
	FileLoader::FileLoader() {



	}

	FileLoader::~FileLoader() {



	}



	/**
	 *	Release Method
	 */
	void FileLoader::Release() {



		CustomResourceLoader<FileLoader>::Release();

	}



	/**
	 *	Load Method
	 */
	Resource* FileLoader::Load(std::wstring path, CoderOption& coderOption) {

		FileResource* result = new FileResource();

		result->content = ResourceManager::GetInstance()->ReadFile(path, coderOption);

		result->path	= path;

		return result;

	}





	/**
	 *
	 *	File Saver
	 *
	 */

	 /**
	  *	Constructors And Destructor
	  */
	FileSaver::FileSaver() {



	}

	FileSaver::~FileSaver() {



	}



	/**
	 *	Release Method
	 */
	void FileSaver::Release() {



		CustomResourceSaver<FileSaver>::Release();

	}



	/**
	 *	Save Method
	 */
	void FileSaver::Save(Resource* resource, CoderOption& coderOption) {

		FileResource* fileResource = (FileResource*)resource;

		ResourceManager::GetInstance()->WriteFile(fileResource->path, fileResource->content, coderOption);

	}

	

	/**
	 *
	 *	File Resource
	 * 
	 */

	/**
	 *	Constructors And Destructor
	 */
	FileResource::FileResource() {



	}

	FileResource::FileResource(std::wstring path) {

		this->path = path;

	}

	FileResource::FileResource(const wchar_t* path) {

		this->path = path;

	}

	FileResource::~FileResource() {



	}



	/**
	 *	Release Method
	 */
	void FileResource::Release() {



		CustomResource<FileResource, FileLoader, FileSaver>::Release();

	}

}