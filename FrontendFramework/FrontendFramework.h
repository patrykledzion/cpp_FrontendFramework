#pragma once
#include "Navigation.h"
namespace nFrontendFramework {
	class FrontendFramework
	{
	private:
		//navigation -> {documents[], defaultDocument, currentDocument[path, DocumentObject], Add("/path", DocumentObject)}
		Navigation navigation;
		//

	public:
		void Init();
		void Update();
		void Draw();
	};


}
