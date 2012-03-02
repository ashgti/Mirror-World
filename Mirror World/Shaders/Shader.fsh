//
//  Shader.fsh
//  Mirror World
//
//  Created by John Harrison on 3/2/12.
//  Copyright (c) 2012 Auburn University. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
