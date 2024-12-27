#include "imageloader.h" 
#include <assert.h>       
#include <fstream>       

using namespace std;

// 加载纹理的函数
GLuint loadTexture(Image* image) {
    GLuint* textures = new GLuint[11];  // 创建一个包含11个纹理ID的数组
    glGenTextures(12, textures);        // 生成12个纹理ID（为纹理数组预留空间）
    glBindTexture(GL_TEXTURE_2D, *textures);  // 绑定第一个纹理到2D纹理目标
    glTexImage2D(GL_TEXTURE_2D,  // 目标纹理类型（2D纹理）
        0,              // 纹理级别（0表示基本级别）
        GL_RGB,         // 纹理格式（RGB）
        image->width, image->height,  // 纹理的宽度和高度
        0,              // 边框宽度（通常为0）
        GL_RGB,         // 像素数据格式（RGB）
        GL_UNSIGNED_BYTE,  // 像素数据类型（无符号字节）
        image->pixels   // 实际的像素数据
    );
    return *textures;  // 返回第一个纹理ID
}

// 定义多个纹理ID变量
GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;
GLuint _textureId7;
GLuint _textureId8;
GLuint _textureId9;
GLuint _textureId10;
GLuint _textureId11;
GLuint _textureId12;

// 初始化渲染的函数
void initRender() {
    glEnable(GL_DEPTH_TEST);  // 启用深度测试
    glEnable(GL_COLOR_MATERIAL);  // 启用颜色材质
    glEnable(GL_BLEND);  // 启用混合（用于透明效果）
    glEnable(GL_NORMALIZE);  // 启用法线归一化
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // 设置混合函数

    // 加载并绑定多个纹理
    Image* image1 = loadBMP("assets/cake.bmp");
    _textureId1 = loadTexture(image1);
    delete image1;
    Image* image2 = loadBMP("assets/pages_2.bmp");
    _textureId2 = loadTexture(image2);
    delete image2;
    Image* image3 = loadBMP("assets/wood.bmp");
    _textureId3 = loadTexture(image3);
    delete image3;
    Image* image4 = loadBMP("assets/cover.bmp");
    _textureId4 = loadTexture(image4);
    delete image4;
    Image* image5 = loadBMP("assets/cvr.bmp");
    _textureId5 = loadTexture(image5);
    delete image5;
    Image* image6 = loadBMP("assets/2cover.bmp");
    _textureId6 = loadTexture(image6);
    delete image6;
    Image* image7 = loadBMP("assets/2cvr.bmp");
    _textureId7 = loadTexture(image7);
    delete image7;
    Image* image8 = loadBMP("assets/3cover.bmp");
    _textureId8 = loadTexture(image8);
    delete image8;
    Image* image9 = loadBMP("assets/3cvr.bmp");
    _textureId9 = loadTexture(image9);
    delete image9;
    Image* image10 = loadBMP("assets/wall.bmp");
    _textureId10 = loadTexture(image10);
    delete image10;
    Image* image11 = loadBMP("assets/sky.bmp");
    _textureId11 = loadTexture(image11);
    delete image11;
    Image* image12 = loadBMP("assets/floor.bmp");
    _textureId12 = loadTexture(image12);
    delete image12;


    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // 设置背景颜色为白色，透明度为1
}

// Image类的构造函数
Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {}

// Image类的析构函数
Image::~Image() {
    delete[] pixels;  // 释放像素数据的内存
}

namespace {
    // 将4字节字符数组转换为整数
    int toInt(const char* bytes) {
        return (int)(
            ((unsigned char)bytes[3] << 24) |
            ((unsigned char)bytes[2] << 16) |
            ((unsigned char)bytes[1] << 8) |
            (unsigned char)bytes[0]
            );
    }

    // 将2字节字符数组转换为短整数（小端序）
    short toShort(const char* bytes) {
        return (short)(((unsigned char)bytes[1] << 8) |
            (unsigned char)bytes[0]);
    }

    // 从文件流中读取4字节并转换为整数
    int readInt(ifstream& input) {
        char buffer[4];
        input.read(buffer, 4);
        return toInt(buffer);
    }

    // 从文件流中读取2字节并转换为短整数
    short readShort(ifstream& input) {
        char buffer[2];
        input.read(buffer, 2);
        return toShort(buffer);
    }

    // 类似于auto_ptr的智能指针，但用于数组
    template<class T>
    class auto_array {
    private:
        T* array;  // 指向数组的指针
        mutable bool isReleased;  // 标记数组是否已释放
    public:
        explicit auto_array(T* array_ = NULL) :
            array(array_), isReleased(false) {
        }

        auto_array(const auto_array<T>& aarray) {
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }

        ~auto_array() {
            if (!isReleased && array != NULL) {
                delete[] array;  // 释放数组内存
            }
        }

        T* get() const {
            return array;
        }

        T& operator*() const {
            return *array;
        }

        void operator=(const auto_array<T>& aarray) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = aarray.array;
            isReleased = aarray.isReleased;
            aarray.isReleased = true;
        }

        T* operator->() const {
            return array;
        }

        T* release() {
            isReleased = true;
            return array;
        }

        void reset(T* array_ = NULL) {
            if (!isReleased && array != NULL) {
                delete[] array;
            }
            array = array_;
        }

        T* operator+(int i) {
            return array + i;
        }

        T& operator[](int i) {
            return array[i];
        }
    };
}

// 加载BMP图像的函数
Image* loadBMP(const char* filename) {
    ifstream input;
    input.open(filename, ifstream::binary);  // 以二进制模式打开文件
    assert(!input.fail() || !"Could not find file");  // 断言文件存在
    char buffer[2];
    input.read(buffer, 2);
    assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");  // 断言文件是BMP格式
    input.ignore(8);
    int dataOffset = readInt(input);  // 读取像素数据的偏移量

    // 读取BMP文件头
    int headerSize = readInt(input);  // 读取头大小
    int width;
    int height;
    switch (headerSize) {
    case 40:
        // V3格式
        width = readInt(input);
        height = readInt(input);
        input.ignore(2);
        assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");  // 断言图像为24位
        assert(readShort(input) == 0 || !"Image is compressed");  // 断言图像未压缩
        break;
    case 12:
        // OS/2 V1格式
        width = readShort(input);
        height = readShort(input);
        input.ignore(2);
        assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
        break;
    case 64:
        // OS/2 V2格式
        assert(!"Can't load OS/2 V2 bitmaps");
        break;
    case 108:
        // Windows V4格式
        assert(!"Can't load Windows V4 bitmaps");
        break;
    case 124:
        // Windows V5格式
        assert(!"Can't load Windows V5 bitmaps");
        break;
    default:
        assert(!"Unknown bitmap format");
    }

    // 读取像素数据
    int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);  // 计算每行的字节数
    int size = bytesPerRow * height;  // 计算总字节数
    auto_array<char> pixels(new char[size]);  // 分配像素数据的内存
    input.seekg(dataOffset, ios_base::beg);  // 跳转到像素数据的位置
    input.read(pixels.get(), size);  // 读取像素数据

    // 将像素数据转换为正确的格式
    auto_array<char> pixels2(new char[width * height * 3]);  // 分配新的像素数据内存
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                pixels2[3 * (width * y + x) + c] =
                    pixels[bytesPerRow * y + 3 * x + (2 - c)];  // 重新排列像素数据
            }
        }
    }

    input.close();  
    return new Image(pixels2.release(), width, height);  // 返回Image对象
}