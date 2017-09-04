//===--- 15.7.cpp - clang-tidy-misra --------------------------------------===//
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "15.7.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchers.h"

namespace clang {
namespace tidy {
namespace misra {
namespace c2012 {

Rule_15_7::Rule_15_7(llvm::StringRef Name, ClangTidyContext *Context)
    : ClangTidyMisraCheck(Name, Context) {}

void Rule_15_7::registerMatchers(ast_matchers::MatchFinder *Finder) {
  using namespace ast_matchers;
  Finder->addMatcher(
      ifStmt(allOf(hasElse(ifStmt(unless(hasElse(compoundStmt())))),
                   unless(hasParent(ifStmt()))))
          .bind("IfStmt"),
      this);
}

void Rule_15_7::checkImpl(
    const ast_matchers::MatchFinder::MatchResult &Result) {
  if (const auto *IS = Result.Nodes.getNodeAs<IfStmt>("IfStmt")) {
    diag(IS->getLocStart());
  }
}

} // namespace c2012
} // namespace misra
} // namespace tidy
} // namespace clang
