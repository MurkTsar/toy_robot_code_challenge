#include "commandexecutor.h"
#include "tabletop.h"
#include <memory>

class Test_CommandExecutor : public ::testing::Test {
protected:
    CommandExecutor executor;
    std::unique_ptr<TableTop> tabletop;

    void SetUp() override {
        tabletop = std::make_unique<TableTop>(5, 5, 1);
    }

    void TearDown() override { }
};