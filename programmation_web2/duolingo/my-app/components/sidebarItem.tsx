"use client";
import React from 'react'
import { Button } from '@/components/ui/button'
import Image from 'next/image'
import Link from 'next/link'
import { usePathname } from 'next/navigation';
type props = {
    label: string, 
    IconSrc: string, 
    href: string
}
export const SidebarItem = ({label, IconSrc, href}: props) => {
  const pathname = usePathname();
  let active = pathname === href;
    return (
    <Button variant={active? "sidebarOutline": "sidebar"} className='justify-start h-[52px]' asChild >
        <Link href={href}>
            <Image src={IconSrc} alt={label} className='mr-5' width={32} height={32}/>
            {label}
        </Link>         
    </Button>

  )
}