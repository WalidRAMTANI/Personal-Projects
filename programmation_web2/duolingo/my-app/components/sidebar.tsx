import React from 'react'
import Image from 'next/image'
import { cn } from '@/lib/utils'
import { SidebarItem } from '@/components/sidebarItem'
import { ClerkLoaded, ClerkLoading, UserButton } from '@clerk/nextjs'
import { Loader } from 'lucide-react'
type Props = {
  className: string
}
export function Sidebar({className}: Props) {
  return (
    <div className={cn('flex h-full lg:w-[256px]  lg:fixed flex-col top-0 left-0 px-4 border-r-2', className)}>
      <div className='pt-8 pl-4 pb-7 flex items-center gap-x-3'>
            <Image src="/mascot.svg" width={40} height={40} alt=''/>
            <h1 className='text-2xl font-extrabold text-green-600 tracking-wide'>Duolingo</h1>
      </div>
      <div className='flex flex-col justify-start gap-y-2 flex-1'>
          <SidebarItem 
            label={"learn"} IconSrc={"/learn.svg"} href={"/learn"}  />
          <SidebarItem 
            label={"leaderboard"} IconSrc={"/leaderboard.svg"} href={"/leaderboard"}  />
          <SidebarItem 
            label={"quests"} IconSrc={"/quests.svg"} href={"/quests"}  />
          <SidebarItem 
            label={"shop"} IconSrc={"/shop.svg"} href={"/shop"}  />
      </div>
      <div className='p-4'>
          <ClerkLoading>
            <Loader className='w-5 h-5 text-muted-foreground'/>
          </ClerkLoading>
          <ClerkLoaded>
            <UserButton afterSignOutUrl='/'/>
          </ClerkLoaded> 
      </div>
    </div>
  )
}