PARAMS = -Wall -lpthread -lglut -lGL -lGLU -lpng -lz
SHAD = -lGLEW

LINES1 = g++ ex1abcslide2.cpp $(PARAMS)
LINES2 = g++ ex1dslide2.cpp $(PARAMS)
LINES3 = g++ ex2slide2.cpp $(PARAMS)
VIEWPORT = g++ ex3slide2.cpp $(PARAMS)
TRANSFORM1 = g++ ex2slide3.cpp $(PARAMS)
TRANSFORM2 = g++ ex1slide3.cpp $(PARAMS)
BRACO = g++ ex12slide4.cpp $(PARAMS)
SCREEN = g++ ex1slide5.cpp $(PARAMS)
RAYTRACING123 = g++ rayTracingSceneReader.cpp rayTracingSceneReader.h rayTracer.h rayTracer.cpp ex123slide12.cpp $(PARAMS)
SHADERS3 = g++ ex3slide13.cpp glcShader.cpp glcShader.h $(PARAMS) $(SHAD)
SHADERS2 = g++ ex2slide13.cpp glcShader.cpp glcShader.h $(PARAMS) $(SHAD)
SHADERS1 = g++ ex1slide13.cpp glcShader.cpp glcShader.h $(PARAMS) $(SHAD)

all:
	$(RAYTRACING123)
	./a.out