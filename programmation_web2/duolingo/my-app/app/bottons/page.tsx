import { Button } from '@/components/ui/button'
import React from 'react'

function ButtonsPage() {
  return (
    <div className='p-4 space-y-4 flex flex-col max-w-[200px]'>
        <Button>
            Default
        </Button>
        <Button variant={'primary'}>
            primary
        </Button>
        <Button variant={'primaryOutline'}>
            primary out line
        </Button>
        <Button variant={'secondry'}>
            secondry
        </Button>
        <Button variant={'secondryOutline'}>
            secondry out line
        </Button>
        <Button variant={'danger'}>
            danger
        </Button>
        <Button variant={'dangerOutline'}>
            danger out line
        </Button>
        <Button variant={'super'}>
            super
        </Button>
        <Button variant={'superOutline'}>
            super out line
        </Button>
        <Button variant={'ghost'}>
            ghost
        </Button>
        <Button variant={'sidebar'}>
            sidebar
        </Button>
        <Button variant={'sidebarOutline'}>
            sidebar out line
        </Button>
    </div>
  )
}

export default ButtonsPage;