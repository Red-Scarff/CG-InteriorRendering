void drawObjectsforMirror() {
	drawTable();
	book1();
	book1top();
	book2();
	book2top();
	book3();
	book3top();
	pages();
	glasscube();
	drawWallM();
	drawFloor();
}

void drawMirrors() {
    GLint buffers = GL_NONE; // 用于存储当前的颜色缓冲区
    glGetIntegerv(GL_DRAW_BUFFER, &buffers); // 获取当前的颜色缓冲区

    glClearStencil(0x00); // 设置模板缓冲区的清除值为0
    glEnable(GL_STENCIL_TEST); // 启用模板测试
    glColorMask(0, 0, 0, 0); // 禁用颜色写入（不绘制颜色到屏幕）

    // 设置模板操作：总是通过模板测试，并用1替换模板缓冲区中的值
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE); // 设置模板操作为替换
    glStencilFunc(GL_ALWAYS, 1, 0xffffffff); // 总是通过模板测试，并将模板缓冲区中的值设置为1

    // 禁用深度测试，开始绘制模板掩码
    glDisable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);


    glNormal3f(0.0f, 0.0f, 1.0f); // 设置法线向量
    glVertex3f(-roomSize, -2.0f, -roomSize); // 设置顶点坐标
    glVertex3f(roomSize, -2.0f, -roomSize);
    glVertex3f(roomSize, 8.0f, -roomSize);
    glVertex3f(-roomSize, 8.0f, -roomSize);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-roomSize, 8.0f, roomSize);
    glVertex3f(roomSize, 8.0f, roomSize);
    glVertex3f(roomSize, -2.0f, roomSize);
    glVertex3f(-roomSize, -2.0f, roomSize);
    glEnd();
    ////////////////////////////////////////////////

    // 重新启用颜色写入
    glDrawBuffer((GLenum)buffers); // 恢复之前的颜色缓冲区
    glColorMask(1, 1, 1, 1); // 启用颜色写入

    // 设置模板测试：仅在模板缓冲区值为1的地方绘制
    glStencilFunc(GL_EQUAL, 1, 0xffffffff); // 仅在模板缓冲区值为1的地方通过测试
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); // 设置模板操作为只读（不修改模板缓冲区）

    // 清除颜色缓冲区和深度缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 启用深度测试，开始绘制镜像
    glEnable(GL_DEPTH_TEST);
    glPushMatrix(); // 保存当前矩阵状态

    // 绘制镜像图像
    // 通过多次缩放和平移，生成镜像效果
    for (float k = 2.0f; k < 20; k = k + 2) {
        glScalef(1.0f, 1.0f, -1.0f); 
        glTranslatef(0.0f, 0.0f, k * roomSize); 
        drawObjectsforMirror(); 
    }

    glPopMatrix(); // 恢复矩阵状态

    // 禁用模板测试和颜色写入
    glDisable(GL_STENCIL_TEST); // 禁用模板测试
    glDrawBuffer(GL_NONE); // 禁用颜色写入

    // 恢复之前的颜色缓冲区
    glDrawBuffer((GLenum)buffers);
}