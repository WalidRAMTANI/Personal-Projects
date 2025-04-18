import { Sheet, SheetContent, SheetTrigger } from "@/components/ui/sheet";
import { Sidebar } from "@/components/sidebar";
import React from 'react'
import { Menu } from "lucide-react";

export function MobileSidebar() {
  return (
    <div>
        <Sheet>
            <SheetTrigger>
                <Menu  className="text-white"/>
            </SheetTrigger>
            <SheetContent className="p-0 z-[100]" side={"left"}>
                <Sidebar className=""/>
            </SheetContent>
        </Sheet>
    </div>
  )
}