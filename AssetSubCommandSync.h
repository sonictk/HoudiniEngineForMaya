#ifndef __AssetSubCommandSync_h__
#define __AssetSubCommandSync_h__

#include "AssetSubCommand.h"

#include <maya/MObject.h>

#include <vector>

class AssetSync;

class AssetSubCommandSync : public AssetSubCommand
{
    public:
	AssetSubCommandSync(
		const MObject &assetNodeObj,
		const MObject &assetTransformObj
		);
	virtual ~AssetSubCommandSync();

	virtual MStatus doIt();
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	virtual bool isUndoable() const;

    protected:
	MObject myAssetNodeObj;
	MObject myAssetTransformObj;

	typedef std::vector<AssetSync*> AssetSyncs;
	AssetSyncs myAssetSyncs;
};

#endif