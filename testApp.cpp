#include <iostream>

#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "SaleMachine.h"

using namespace std;

class Test : public CPPUNIT_NS::TestCase
{
    CPPUNIT_TEST_SUITE(Test);

    CPPUNIT_TEST(TestMethod1);
    CPPUNIT_TEST(TestMethod2);
    CPPUNIT_TEST(TestMethod3);
    CPPUNIT_TEST(TestMethod4);
    CPPUNIT_TEST(TestMethod5);
    CPPUNIT_TEST(TestMethod6);
    CPPUNIT_TEST(TestMethod7);
    CPPUNIT_TEST(TestMethod8);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void) {}
    void tearDown(void) {}

protected:
    void TestMethod1();
    void TestMethod2();
    void TestMethod3();
    void TestMethod4();
    void TestMethod5();
    void TestMethod6();
    void TestMethod7();
    void TestMethod8();

private:
    string res[5] = {"很抱歉，没有", "请取走", "拿好5元，请取走", "没有零钱找，退您10元", "错误指令！"};
    SaleMachine sm;
    string drink;
};

void Test::TestMethod1()
{
    drink = "cola";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[4]);
}

void Test::TestMethod2()
{
    drink = "beer";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);

    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[0] + drink);
}

void Test::TestMethod3()
{
    drink = "orange";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[1] + drink);
    
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 5), res[0] + drink);
}

void Test::TestMethod4()
{
    drink = "beer";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 11), res[4]);
}

void Test::TestMethod5()
{
    drink = "beer";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);

    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[0] + drink);
}

void Test::TestMethod6()
{
    drink = "orange";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);

    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[0] + drink);
}

void Test::TestMethod7()
{
    drink = "cola";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[4]);
}

void Test::TestMethod8()
{
    drink = "orange";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    drink = "beer";
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);
    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[2] + drink);

    CPPUNIT_ASSERT_EQUAL(sm.sale(drink, 10), res[3]);
}

CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main(int argc, char **argv)
{
    // Create the event manager and test controller
    CPPUNIT_NS::TestResult controller;

    // Add a listener that colllects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);

    // Add a listener that print dots as test run.
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);

    // Add the top suite to the test runner
    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);

    return result.wasSuccessful() ? 0 : 1;
}
/*
g++ -fprofile-arcs -ftest-coverage testApp.cpp SaleMachine.h SaleMachine.cpp -lcppunit -ldl -o testApp
./testApp
gcov SaleMachine.cpp
lcov -c -d ./ -o app.info
genhtml app.info -o cc_result
 */