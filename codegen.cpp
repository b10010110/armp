#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/IRBuilder.h>

int main(int argc, char *argv[])
{
    llvm::LLVMContext &context = llvm::getGlobalContext();

    /* create module */
    llvm::Module *mod = 
        new llvm::Module("my_mod", context);

    /* create function */
    llvm::FunctionType *func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(context), false);
    llvm::Function *func =
        llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "my_func", mod);

    /* create basic block */
    llvm::BasicBlock *bb =
        llvm::BasicBlock::Create(context, "my_bb", func);

    /* create instruction */
    llvm::IRBuilder<> *builder = new llvm::IRBuilder<>(context);
    builder->SetInsertPoint(bb);
    builder->CreateBr(bb);

    /* dump generated code */
    mod->dump();
  
    return 0;
}
