#include "WorkingWithDataLinker.h"

void WorkingWithDataLinker::append(std::unique_ptr<WorkingWithDataLinker> command)
{
    listCommand.push_back(std::move(command));
}

void WorkingWithDataLinker::append(WorkingWithDataLinker* command)
{
    std::unique_ptr<WorkingWithDataLinker> copyCommand{command};
    listCommand.push_back(std::move(copyCommand));
}

void WorkingWithDataLinker::execute()
{
    foreach(auto command, listCommand)
    {
        if(!command->executeImplementationPart())
            break;
    }
}
