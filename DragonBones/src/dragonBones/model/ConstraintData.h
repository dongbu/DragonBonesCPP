/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2012-2017 DragonBones team and other contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
//
// Created by liangshuochen on 09/06/2017.
//

#ifndef DRAGONBONESCPP_CONSTRAINTDATA_H
#define DRAGONBONESCPP_CONSTRAINTDATA_H

#include "../core/BaseObject.h"

DRAGONBONES_NAMESPACE_BEGIN
/**
 * @internal
 * @private
 */
class ConstraintData : public BaseObject 
{
    ABSTRACT_CLASS(ConstraintData)

public:
    int order;
    std::string name;
    const BoneData* target;
    const BoneData* root;
    const BoneData* bone;

protected:
    virtual void _onClear() override;

public: // For WebAssembly.
    const BoneData* getTarget() const { return  target; }
    void setTarget(const BoneData* value) { target = value; }

    const BoneData* getBone() const { return bone; }
    void setBone(const BoneData* value) { bone = value; }

    const BoneData* getRoot() const { return root; }
    void setRoot(const BoneData* value) { root = value; }
};
/**
 * @internal
 * @private
 */
class IKConstraintData : public ConstraintData 
{
    BIND_CLASS_TYPE_A(IKConstraintData);

public:
    bool scaleEnabled;
    bool bendPositive;
    float weight;

protected:
    virtual void _onClear() override;
};

DRAGONBONES_NAMESPACE_END
#endif //DRAGONBONESCPP_CONSTRAINTDATA_H
